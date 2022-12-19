```
int fib(int N){    
    if(N==0||N==1) return N;
    int a=0,b=1;
    for(int i=2;i<=N;i++){
        b=a+b;
        a=b-a;        
    }
    return b;
}
```
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户