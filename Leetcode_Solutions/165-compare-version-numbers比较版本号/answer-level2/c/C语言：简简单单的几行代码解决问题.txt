![QQ截图20190916094432.png](https://pic.leetcode-cn.com/3957e4568b08f2ad1616c8a805486aeb5e60710f327668bc200d4de9fe882169-QQ%E6%88%AA%E5%9B%BE20190916094432.png)

**先解析每个版本，然后放到数组中，最后依次比较大小
注意：1.0   和   1.0.0.0   的大小是一样的**
```
int compareVersion(char * version1, char * version2){
    if (version1 == NULL || version2 == NULL) return -1;
    int *val1 = (int *)calloc(1024, sizeof(int));
    int *val2 = (int *)calloc(1024, sizeof(int));
    int len1 = strlen(version1), top1 = 0;
    int len2 = strlen(version2), top2 = 0;
    int i, n;
    for (i = 0, n = 0; i < len1; ++i) {  //解析版本1
        if (version1[i] == '.') {
            val1[top1++] = n;
            n = 0;
        }else n = n*10 + (version1[i] & 0x0f);
    }
    val1[top1++] = n;
    for (i = 0, n = 0; i < len2; ++i) {  //解析版本1
        if (version2[i] == '.') {
            val2[top2++] = n;
            n = 0;
        }else n = n*10 + (version2[i] & 0x0f);
    }
    val2[top2++] = n;
    for (i = 0; i < top1 && i < top2; ++i) {  //比较版本大小
        if      (val1[i] > val2[i]) return 1;
        else if (val1[i] < val2[i]) return -1;
    }
    if (i < top1) {  //由于可能有的版本还没遍历完
        while (i < top1) if (val1[i++]) return 1;  //只要版本后面的数字出现的不是0，就意味着两个版本不一样
    }else{
        while (i < top2) if (val2[i++]) return -1;
    }
    return 0;
}
```
