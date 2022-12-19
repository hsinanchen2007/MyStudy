方法一：（利用异或运算符）
```c
int hammingDistance(int x, int y){
    int xor,res=0;
    xor=x^y;
    while(xor!=0){
        if(xor%2!=0) res++;
        xor=xor/2;
    }
    return res;
}
```
方法二：
```c
int hammingDistance(int x, int y){
    int tmp,res=0;
    if(x<y){
        tmp=x;
        x=y;
        y=tmp;
    }
    while(y>0){
        if(x%2!=y%2) res++;
        x=x/2;
        y=y/2;
    }
    while(x>0){
        if(x%2==1) res++;
        x=x/2;
    }
    return res;
}
```