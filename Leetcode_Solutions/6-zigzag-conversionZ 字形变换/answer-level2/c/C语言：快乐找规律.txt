
```
char * convert(char * s, int numRows){
    if (numRows == 1)
        return s;
    int len = strlen(s);
    char *res = (char*)malloc((len + 1) * sizeof(char));
    int *a = (int*)malloc(numRows * sizeof(int)), *b = (int*)malloc(numRows * sizeof(int));
    int i, j, k = 0;

    a[0] = b[0] = a[numRows - 1] = b[numRows - 1] = 2 * (numRows - 1);//第0行和第(numRows - 1)行值固定不变
    //a, b数组存储交替变换的间隔值
    for (i = 1; i < numRows / 2 + numRows % 2; i++){
        a[i] = 2 * (numRows - 1 - i);
        b[i] = 2 * i;
        a[numRows - 1 - i] = b[i];
        b[numRows - 1 - i] = a[i];
    }
    for (i = 0; i < numRows; i++){
    	int cnt = 0;
        for (j = i; j < len; ){
            res[k++] = s[j];
            cnt++;
            if (cnt & 1)
                j += a[i];
            else
                j += b[i];  
        }
    }
    res[k] = '\0';
    return res;
}

```

