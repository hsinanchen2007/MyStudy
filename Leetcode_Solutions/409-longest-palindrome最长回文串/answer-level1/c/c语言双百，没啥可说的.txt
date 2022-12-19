

### 代码

```c
int longestPalindrome(char * s){
    int map[52] = {0};
    int result = 0;
    int hasSin = false;
    while(*s != '\0'){
        if (*s > 96){
            map[*s - 'a' + 26] += 1;
        }else{
            map[*s - 'A'] += 1;
        }
        s++;
    }
    for(int i = 0; i < 52; i++){
        if (map[i] != 0 && (map[i] & 0x0001) == 0){
            result += map[i] & 0xFFFE;
        }else if(map[i] != 0){
            result += map[i] & 0xFFFE;
            hasSin = true;
        }
    }
    return hasSin ? result + 1 : result;
}
```