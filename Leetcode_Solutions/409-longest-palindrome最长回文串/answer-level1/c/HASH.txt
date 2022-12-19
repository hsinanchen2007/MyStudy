### 解题思路
hash表！

### 代码

```c
int longestPalindrome(char * s){
    int stringBig[26] = {0};
    int stringSmall[26] = {0};
    int i = 0;
    int result = 0;
    int flag = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            stringBig[s[i] - 65]++; 
        }
        if (s[i] >= 97 && s[i] <= 122) {
            stringSmall[s[i] - 97]++; 
        }
    }
    for (i = 0; i < 26; i++ ) {
        if (stringBig[i] > 0) {
            result = result + stringBig[i] / 2 * 2;
        }

        if (stringSmall[i] > 0) {
            result = result + stringSmall[i] / 2 * 2;
        }
        if (stringBig[i] % 2 == 1 || stringSmall[i] % 2 == 1) {
            flag = 1;
        }
    }

    return result + flag;
}
```