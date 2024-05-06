#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int random(int random){
    return random = random + 1;
}

int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 2)) + min;
}

int checkindex(int list[], int size) {
    int *p;
    p = list;
    int *q;
    q = list;
    int i, count = 0;

    for (i = 0; i < size; i++) {
        if (*p == *q && p != q) {
            break;
        } else {
            q++;
        }
        count++;
    }
    return count;
}

int main(){
    int N,i,g=1,x,y,j;
    int z;
    int r;
    int list[100];
    printf("Enter N to factorized : ");
    scanf("%d",&N);
    for(i=0;i<=N-1;i++){
        g=random_number(2,N-1);
        if(gcd(g,N) != 1){
            printf("Your number is %d X %d",g,N/g);
            return 0;
        }
        while(1){
            if(gcd(g,N) != 1){
                printf("Your number is %d X %d",g,N/g);
                return 0;
            }
            if(gcd(g,N) == 1){
                for(x=0;x<=N;x++){
                    y = fmod(pow(g,x), N);
                    list[x] = y;
                    if(list[0]==list[x]){ //ลองใส่ && list[1]==list[x+1]
                        int size = sizeof(list) / sizeof(list[0]);
                        z = checkindex(list,size);
                        r = z;
                        if(r % 2 != 0){
                            g=g+1;
                            break;
                        }
                        if((fmod(pow(g,r), N) == -1)){
                            g=g+1;
                            break;
                        }
                    }
                    // break;   //ลองสลับ comment ดู 
                }
            // break;
            if(gcd(g,N)!=1){
                g=random_number(2,N-1);
            }
            else{
                break;
            }
        }
        if(fmod(pow(g,r/2),N) == -1){
            g=random_number(2,N-1);
        }
        }
    
    }
    int p, q;
    p = gcd((pow(g,r/2)+1),N);
    q = gcd((pow(g,r/2)-1),N);
    printf("N can be factorized by %d X %d\n",p,q);
    printf("g = %d\n",g);
    printf("r = %d\n",r);
    for(i=0;i<=N;i++){
        printf("%d, ",list[i]);
    }

}