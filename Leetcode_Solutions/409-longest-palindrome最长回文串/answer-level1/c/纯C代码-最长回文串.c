### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char * s){
    int count[2][26] = {0};
    int i = 0;
    int maxLen = 0;
    bool flag = false;
    while(s[i] != '\0'){
        if (s[i] >= 'a' && s[i] <= 'z'){
            count[0][s[i] - 'a']++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z'){
            count[1][s[i] - 'A']++;
        }
        i++;
    }

    for (i=0; i<26; i++){
        maxLen = maxLen + count[0][i]/2*2 + count[1][i]/2*2;
        if (flag == false && (count[0][i]%2 == 1 || count[1][i] == 1)){
            maxLen++;
            flag = true;
        }
    }

    return maxLen;
}
```