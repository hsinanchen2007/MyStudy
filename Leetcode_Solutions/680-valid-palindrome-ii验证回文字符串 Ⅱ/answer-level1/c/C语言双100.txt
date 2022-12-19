### 解题思路
删除一个字符，即多一次机会，可以删除左边或者删除右边，因此在遇到不相同字符的时候，分别判断左边+1或者右边-1的情况，只要有一种满足回文就return
true，否则return false

### 代码

```c
bool isPalindrome(char *s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(char * s){
    if (strlen(s) == 0) {
        return true;
    }
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
    }
    return true;
}


```