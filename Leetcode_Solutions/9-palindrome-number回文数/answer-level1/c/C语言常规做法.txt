在此做法中，不需要将整数转为字符串。
```c
bool isPalindrome(int x){
    int mirror=0,y=x;
    if (x<0) return 0;
    while(x>0){
        if ((mirror*10.0+x%10)>=2147483648) return 0;
        mirror=mirror*10+x%10;
        x=x/10;
    }
    if (mirror==y) return 1;
    else return 0;
}
```