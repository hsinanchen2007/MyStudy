//该题目与整数反转类似，注意到负数肯定不是回文数，所以只需要对正数进行判断即可。
```


bool isPalindrome(int x){
    char * s = (char *) malloc(100 * sizeof(char));
    memset(s, 0, 100 * sizeof(char));
    if(x < 0) {
        return false;
    }
    int xtemp = x;
    int value;
    int num = 0;
    while(xtemp > 0) {
        value = xtemp % 10;
        xtemp = xtemp / 10;
        s[num++] = value;
    }
    int length = num - 1;
    int res = 0;
    for(int i = 0; i < num; i++) {
        res += s[i] * pow(10, length--);
    }
    if(res == x) {
        return true;
    }
    return false;
    
}


```
