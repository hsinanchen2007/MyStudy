```c
int reverse(int x){
    if(x==-2147483648) return 0;

    int flag=-1,result=0;
    if (x>0) flag=1;
    x=x*flag;
    while(x!=0){
        if (result*10.0+x%10>=2147483648)
            return 0;
        result=result*10+x%10;
        x=x/10;
    }
    return result*flag;
}
```