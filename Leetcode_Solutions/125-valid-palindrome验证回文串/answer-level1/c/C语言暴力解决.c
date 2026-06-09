### 解题思路
执行用时 :
748 ms, 在所有 C 提交中击败了5.62%的用户
内存消耗 :6.2 MB, 在所有 C 提交中击败了100.00%的用户

暴力解决，先将大写字母转成小写，然后忽略除了字母和数字之外的元素，重新构造字符串，最后就可以判断是否回文了

### 代码

```c
bool isPalindrome(char * s){
    if (strlen(s) == 0) {
        return true;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }
    int normalLen = 0;
    char normal[strlen(s)];
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            normal[normalLen] = s[i];
            normalLen++;
        }
    }
    for (int i = 0, j = normalLen - 1; i < j; i++, j--) {
        if (normal[i] != normal[j]) {
            return false;
        }
    }
    return true;
}
```