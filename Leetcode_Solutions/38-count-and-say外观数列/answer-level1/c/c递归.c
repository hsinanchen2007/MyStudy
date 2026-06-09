

```
char * countAndSay(int n){
    char *pre, *num;
    int len = 0;
    int k = 1;
    int t = -2;
    int p = -1;
    pre = (char *)malloc(sizeof(char) * 4500);//保存当前字符串
    num = (char *)malloc(sizeof(char) * 4500);//保存上一层字符串 
    
    if (n == 1) {
        return "1";
    } else if (n == 2) {
        return "11";
    }else {
        num = countAndSay(n - 1);
        len = strlen(num);
        for (int i = 0; i < len; i++) {
            if (num[i + 1] == num[i]) {
                k++;
            } else {
                pre[t = t + 2] = k + '0';
                pre[p = p + 2] = num[i];
                k = 1;
            }
        }
        pre[p + 1]='\0';
        return pre;
    }
    return 0;
}
```
