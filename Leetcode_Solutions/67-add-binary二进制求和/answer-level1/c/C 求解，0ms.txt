```
char * addBinary(char * a, char * b) {
    int la = strlen(a) - 1;
    int lb = strlen(b) - 1;
    int len = la > lb ? la+2 : lb+2;     //取最长
    char *ans = malloc(len+1);           //答案数组多申请一位
    ans[len]=ans[len-1]='\0';            //处理下末尾
    for(int tag = len = 0; tag || la >= 0 || lb >= 0; la--, lb--) {  //有进位或者位数还没有加完
        int an = la < 0 ? 0 : a[la] - '0';      //如果位数用完则相当于补位 '0'
        int bn = lb < 0 ? 0 : b[lb] - '0';      //同上
        ans[len++] = (an ^ bn ^ tag) ? '1' : '0';   //判断加过之后的结果
        tag = an + bn + tag > 1;      //更新进位标志
    }
    for(int i = 0, j = len - 1; i <j; i++, j--) {   //翻转
        char t = ans[i];
        ans[i] = ans[j];
        ans[j] = t;
    }
    return ans;
}
```

思路如注释
