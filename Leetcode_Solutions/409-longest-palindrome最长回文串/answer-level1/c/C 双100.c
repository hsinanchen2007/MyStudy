### 解题思路


### 代码

```c
int longestPalindrome(char * s){
    int res = 0, *hash = (int*)calloc(58, sizeof(int)); // 122-65+1
    for(int i = 0; i < strlen(s); i++){
        hash[s[i]-'A']++;
        if(hash[s[i]-'A']%2==0) res+=2;
    }
    for(int i = 0; i < 58; i++){
        if(hash[i]%2!=0)    return res+1;
    }
    return res;
}
```