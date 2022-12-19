```c
bool isPowerOfFour(int num){
    if(num<=0) return 0;
    while(num-1){
        if(num%4!=0) return 0;
        num=num/4;
    }
    return 1;
}
```