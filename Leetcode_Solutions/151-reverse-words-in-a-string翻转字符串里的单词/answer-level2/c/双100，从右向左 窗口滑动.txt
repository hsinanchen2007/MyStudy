执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6 MB, 在所有 C 提交中击败了100.00%的用户
### 解题思路
找出特例：没有空格；所有都是空格；
先找到第一个非空字符r；
从右向左遍历：查找空字符l，并保存中间的单词并添加空格；反复查找第一个非空字符r后 再查找空字符l；
临界条件：找不到非空字符, 退出循环 r < 0；确定r后找不到空字符l，退出循环；
记着去除最后一个空格；
### 代码

```c
char * reverseWords(char * s){
    if (s == NULL) {
        return NULL;
    }
    int len  = strlen(s);
    char *out = malloc (len + 1);
    memset(out, 0, len + 1);

    if (strchr(s, ' ') == NULL) {
        strcpy(out, s);
        return out;
    }

    int i = len - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    if (i == -1) {
        return out;
    }
    char *m = out;

    int l = -1;
    int r = i;
    //printf("r new:%d\n", r);
    int flag = 0;
    for (; i >= 0; i--) {
        if (s[i] != ' ') {
            continue;
        }

        l = i;
        int cplen = r - l;
        //printf("pl:%s,cplen:%d\n", &s[l],cplen);
        memcpy(m, s + l + 1, cplen);
        m += cplen;
        *(m++) = ' ';
        //printf("out:%s\n", out);
        while (i >= 0 && s[i] == ' ') {
            i--;
            r = i;
        }
        if (i == -1) {
            break;
        }
        //printf("new r :%d\n", r);
    }

    if (r >= 0) {
        int cplen = r + 1;
        memcpy(m, s, cplen);
        m += cplen;
        //printf("out:%s\n", out);   
    } else if (m > 0) {
        *(m - 1) = '\0';
    }

    return out;
}
```