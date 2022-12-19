将num反复除以2，直到不能被2整除；再对除数3和5进行同样的操作。最后如果num的值为1，则是丑数。
```c
bool isUgly(int num){
    if(num==0) return 0;
    while(num%2==0) num=num/2;
    while(num%3==0) num=num/3;
    while(num%5==0) num=num/5;
    return num==1;
}
```