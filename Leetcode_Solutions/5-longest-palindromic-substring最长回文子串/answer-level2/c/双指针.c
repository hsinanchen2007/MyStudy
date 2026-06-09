### 解题思路
使用双指针思路，m表示子串头，n表示子串尾，m对整个字符串进行遍历，i和j双指针开始分别指向子串头和尾用来滑动判断是否满足回文串要求，相等的话表示满足回文要求就i++,j--向中心汇聚，不相等说明就不满足回文要求，m不动，n--，并且i和j分别从新指向m和n。
这道题开辟空间的长度要求大于2*len+1，否则提交时会报错，这一点没有想明白，子串的长度不应该小于等于输入字符串的长度len吗？看其他一个兄弟的解题思路是说要考虑字符间的空格，所以使用2*len+1，没太明白什么意思，有明白的兄弟可以留言指导一下。。。
### 代码

```c
char * longestPalindrome(char * s){
    int len  = strlen(s);
    int m, n, i, j;
    int maxCur = 0;
    int maxMax = 0;
    char *retChar = (char*)malloc(sizeof(char) * (len * 2 + 1));
    memset(retChar, 0, (len * 2 + 1));
    for (m = 0; m < len; m++) {
        n = len - 1;
        i = m;
        j = n;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                n--;
                i = m;
                j = n;
            }
        }
        maxCur = n - m + 1;
        if (maxMax < maxCur) {
            maxMax = maxCur;
            strncpy(retChar, (s + m), maxMax);
            retChar[maxMax] = 0;
        }
    }
    
    return retChar;
}
```