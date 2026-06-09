**将26进制转为10进制即可**

```c
int titleToNumber(char * s){
    if(!s || s == "")
        return 0;
    int len = strlen(s), ans = 0;
    for(int i = len - 1; i >= 0; i--){
        ans += (s[i] - 'A' + 1) * pow(26, len - i - 1);
    }
    return ans;
}
```