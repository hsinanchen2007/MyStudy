```c
bool isPowerOfThree(int n){
    int result=n;
    if(n==0) return 0;
    while(result!=1){
        if(result%3!=0||result==1) break;
        result=result/3;}
    if (result!=1) return 0;
    else return 1;
}
```