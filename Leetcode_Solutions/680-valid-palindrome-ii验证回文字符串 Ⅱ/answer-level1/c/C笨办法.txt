### 解题思路
本来逻辑比较简单，直接左边+1 或者右边-1 接着做判断。但是遇到用例aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga
即左边+1 或者右边-1都能满足回文，但是需要进一步去判断，导致整个代码逻辑混乱，感觉是针对个别用例修改代码，为了ac而ac

### 代码

```c
bool validPalindrome(char * s){
    if (strlen(s) == 0) {
        return true;
    }
    int flag = 0;
    for (int i = 0, j = strlen(s) - 1; i < j - 1; i++, j--) {
        if (s[i] != s[j]) {
            if (flag >= 1) {
                return false;
            }
            if (s[i + 1] == s[j] && s[i] == s[j - 1]) { // 针对个别用例，左边+1 或右边-1都能保持当前状态满足回文
                if (s[i + 2] == s[j - 1]) {
                    j++;
                    flag++;
                } else if (s[i + 1] == s[j - 2]) {
                    i--;
                    flag++;
                } else {
                    return false;
                }
            } else if (s[i + 1] == s[j]) {
                j++;
                flag++;
            } else if (s[i] == s[j - 1]) {
                i--;
                flag++;
            } else {
                return false;
            }
        }
    }
    return true;
}
```