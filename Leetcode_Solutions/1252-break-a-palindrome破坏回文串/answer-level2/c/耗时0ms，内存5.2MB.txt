### 解题思路
从头开始向中间遍历，不等于a的直接令其为a然后返回。若遍历到中间仍然是a，就令最后有一个字符为b然后返回。

### 代码

```c
char * breakPalindrome(char * palindrome){
    int i;
    int size = -1;
    while(palindrome[++size] != '\0');
    if (size <= 1) return "";
    int end = size / 2;
    for (i = 0; i < end; i++) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome[size - 1] = 'b';
    return palindrome;
}
```