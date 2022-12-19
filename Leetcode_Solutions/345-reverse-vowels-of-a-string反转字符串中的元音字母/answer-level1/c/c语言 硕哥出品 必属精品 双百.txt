### 解题思路
此处撰写解题思路

### 代码

```c
bool ifChar(char c) {
    char *s = "aeiouAEIOU";
    for (int i = 0; i < 10; i++) {
        if (c == s[i]) {
            return true;
        }
    }
    return false;
}

char * reverseVowels(char * s){
    int len = strlen(s);
    int i= 0;
    int j = len - 1;
    char temp;
    while (i < j) {
        if (ifChar(s[i]) && (ifChar(s[j]))){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        while(!ifChar(s[i]) && (i < j)) {
            i++;
        }
        while(!ifChar(s[j]) && (i < j)) {
            j--;
        }
    }
    return s;
}
```