### 解题思路
使用字符处理函数

### 代码

```c
bool isPalindrome(char * s){
    int i = 0;
    int len = strlen(s);
    int j = len - 1;

    while (i < j) {
        if ((int)isalnum(s[i]) == 0) {
            i++;
            continue;
        }
        if ((int)isalnum(s[j]) == 0) {
            j--;
            continue;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
```