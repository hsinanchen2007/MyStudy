先从str1和str2中找到最短的字符串，然后利用该字符串从后往前找最大因子

```
int TOP = 0;
char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *order_str  = (len1 > len2 ? str2 : str1);
    int   o_len      = (len1 > len2 ? len2 : len1);
    char *tmp_str    = (char *) malloc(1024);
    strcpy(tmp_str, order_str);
    
    for (int tmp_len = o_len; tmp_len > 0; --tmp_len, tmp_str[tmp_len] = '\0') {
        if (!(len1 % tmp_len) && !(len2 % tmp_len)) { //字符串长度必须整除
            int tmp_1 = find_str(str1, tmp_str);
            if (tmp_1 < tmp_len || TOP < len1) continue;  //判断是否同时都比较到字符串尾部
            int tmp_2 = find_str(str2, tmp_str);
            if (tmp_2 < tmp_len || TOP < len2) continue;
            return tmp_str;
        }
    }

    return tmp_str;
}

int find_str(char *master, char *order)
{
    TOP = 0;
    int j;
    while (master[TOP]) {
        for (j = 0; order[j]; ++j) {//重复比较
            if (order[j] != master[TOP]) return j;
            ++TOP;
        }
    }
    return j;
}
```
