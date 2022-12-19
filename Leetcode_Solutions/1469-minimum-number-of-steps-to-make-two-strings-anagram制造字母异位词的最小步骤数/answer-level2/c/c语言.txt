![1584506327(1).jpg](https://pic.leetcode-cn.com/616dad0259ef89c4b4a0297ed99bf2d5bca8e01e1688d735b50f98661ea3f6a8-1584506327\(1\).jpg)
```

int minSteps(char * s, char * t){
    int hash[26];
    memset(hash, 0, sizeof(hash));
    char *c = s;
    while(*c != '\0'){
        hash[*c - 'a']++;
        c++;
    }
    int len = strlen(s);
    c = t;
    while(*c != '\0'){
        if(hash[*c - 'a'] > 0){
            len--;
            hash[*c - 'a']--;
            
        }
        c++;
    }
    return len;
}
```
