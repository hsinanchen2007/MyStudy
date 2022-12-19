# 思路
嘿嘿，奥利给
# 代码

```
char * freqAlphabets(char * s){
    int preTwo = 0;
    int i = 0;
    int k = 0;
    int length = 0;
    for (length = 0; s[length]; length++);
    char *result = (char*)calloc(sizeof(char), length);
    
    for (i = 0; s[i]; ) {
        if (i+2 < length && s[i+2] == '#') {
            result[k++] = 'a'+((s[i] - '0') * 10 + (s[i+1] - '0')-1);
            i+=3;
        } else {
            result[k++] = 'a'+(s[i] - '1');
            i++;
        }
    }
    return result;
}```
