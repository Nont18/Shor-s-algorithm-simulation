#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int gcd(unsigned long long int a, unsigned long long int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *insert(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int checkindex(Node *head) {
    Node *p = head;
    Node *q = head;
    int count = 0;

    while (p != NULL) {
        while (q != NULL) {
            if (p != q && p->value == q->value) {
                return count;
            }
            q = q->next;
            count++;
        }
        p = p->next;
        q = head;
    }
    return -1; // Not found
}

unsigned long long int TestPrime(unsigned long long int n) {
    unsigned long long int i;
    for (i = 2; i <= floor(sqrt(n)); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


#define PI 3.14159265358979323846

void applyQFT(Node *head) {
    int N = 0;
    Node *current = head;
    while (current != NULL) {
        N++;
        current = current->next;
    }

    double *input = (double *)malloc(N * sizeof(double));
    double *output = (double *)malloc(N * sizeof(double));

    current = head;
    int i = 0;
    while (current != NULL) {
        input[i] = current->value;
        current = current->next;
        i++;
    }

    for (int k = 0; k < N; k++) {
        output[k] = 0;
        for (int j = 0; j < N; j++) {
            output[k] += input[j] * cos(2 * PI * k * j / N) + sin(2 * PI * k * j / N);
        }
    }

    current = head;
    i = 0;
    while (current != NULL) {
        current->value = (int)round(output[i]);
        current = current->next;
        i++;
    }

    free(input);
    free(output);
}




int main() {
    int N, g = 1, x, y;
    unsigned long long int r;
    Node *list = NULL;
    int qubit;
    int done = 0;
    printf("Welcome to the simulation of Shor's algorithm.\n");
    printf("There are four restrictions for Shor's algorithm:\n");
    printf("1) The number to be factored (n) must be >= 15.\n");
    printf("2) The number to be factored must be odd.\n");
    printf("3) The number must not be prime.\n");
    printf("4) The number must not be a prime power.\n");
    printf("");
    printf("Enter N to factorize: ");
    scanf("%d", &N);

    if (N % 2 == 0) {
        printf("\tError, the number must be odd!\n");
        exit(EXIT_FAILURE);
    }

    if (TestPrime(N)) {
        printf("\tError, the number must not be prime!");
        exit(EXIT_FAILURE);
    }

    qubit = N * N;

    while (!done) {
        g = g + 1; // apply superposition to g so g can be 0 to N-1
        // if (gcd(g, N) != 1) {
        //     printf("r = %llu\n", r);
        //     printf("guess (g) = %d\n",g);
        //     printf("Your number is %d X %d", g, N / g);
        //     exit(EXIT_SUCCESS);
        // }

        if (gcd(g, N) == 1) {
            for (x = 0; x <= N - 1; x++) {
                y = fmod(pow(g, x), N);
                list = insert(list, y);
                int z = checkindex(list);
                if (z != -1) {
                    r = z;
                    if (r % 2 != 0 || fmod(pow(g, r), N) == -1) {
                        done = 0;
                    }
                    
                }
            }
        
        // done = 1;

        if (gcd(g, N) != 1) {
            done = 0;
        }
        if (fmod(pow(g, r / 2), N) == -1) {
            done = 0;
        }

    if(gcd(g, N) == 1 && fmod(pow(g, r / 2), N) != -1 && r % 2 == 0 && fmod(pow(g, r), N) != -1){
        done = 1;
    }
        }

    }

    unsigned long long int p;
    unsigned long long int q;
    p = gcd((pow(g, r / 2) + 1), N);
    q = gcd((pow(g, r / 2) - 1), N);
    printf("N can be factorized by %llu X %llu\n", p, q);
    printf("g=%d\n",g);
    printf("(pow(g, r / 2) + 1) = %d\n",(pow(g, r / 2) + 1));
    printf("(pow(g, r / 2) - 1) = %d\n",(pow(g, r / 2) - 1));
    // printf("g = %d\n", g);
    printf("r = %llu\n", r);
    printf("List: ");
    Node *current = list;
    while (current != NULL) {
        printf("%d, ", current->value);
        current = current->next;
    }

    // Free memory allocated for the linked list
    freeList(list);

    return 0;
}
