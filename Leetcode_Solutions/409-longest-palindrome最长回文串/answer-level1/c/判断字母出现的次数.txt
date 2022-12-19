### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char * s){

    if (s == NULL || *s == '\0') {
        return 0;
    }

    int markS[26] = {0};
    int markB[26] = {0};
    int sLen = strlen(s);
    int sum = 0;
   // if (sLen == 1) {
  //      return 1;
   // }
    for (int i = 0;i < sLen;i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            markS[s[i] - 'a']++;
       }
       else if (s[i] >= 'A' && s[i] <= 'Z') {
           markB[s[i] - 'A']++;
        }
    }

    for (int i = 0;i < 26;i++) {
        sum += markS[i]/2;
        sum += markB[i]/2;
    }

    if (2*sum == sLen) {
        return sLen;
    }
  
    return 2*sum + 1;


}
```