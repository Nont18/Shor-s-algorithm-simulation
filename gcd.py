def gcd(a,b):
    while((a!=b)and(a,b!=0)):
        if a>b:
            a=a-b
        else:
            b=b-a
    return a,b

print(max(gcd(65,104)))