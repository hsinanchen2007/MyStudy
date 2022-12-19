### 解题思路
嘿嘿

### 代码

```c
int longestPalindrome(char * s){
    int* map = (int *)calloc(sizeof(int), 52);
    int length = 0;
    for (length = 0; s[length]; length++) {
        if ('a' <=s [length] && s[length] <= 'z') {
            map[s[length]-'a']++;
        } else {
            map[s[length]-'A'+26]++;
        }
    }
    int result = 0;
    bool hasOdd = false;
    for (int i = 0; i < 52; i++) {
        if (map[i]%2 == 0) {
            result+=map[i];
        } else {
            hasOdd = true;
            result+=(map[i]-1);
        }
    }

    return result+(hasOdd?1:0);
}
```