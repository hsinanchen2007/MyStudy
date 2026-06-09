题解区用C语言解的好少啊，自己的代码虽然辣鸡，但还是希望对看到的朋友有所启发，欢迎你们评论和指点
```



char * countAndSay(int n){
    char a[100001] = {0}, b[100001] = {0};
    char *res = a;
    int i, j, k, cnt = 1, len = 1;

    a[0] = '1';
    n--;
    if (n == 0)
        return res;
    for (i = 0; i < n; i++){
    	k = 0;
        for (j = 0; j < len; j++){
            if (a[j] == a[j + 1]){
                cnt++;
            }
            else{
            	b[k++] = cnt + '0';
				b[k++] = a[j];
                cnt = 1;
            }          
        }
        len = k;
        b[len] = '\0';
        strcpy(a, b);
    }
    return res;
}
```
