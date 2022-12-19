计算每个字母出现的次数，每个字母出现的总次数除以该字母在单词中出现的次数，取最小值。  
其实是hash的思想，key就是`(字母-'a')`

```c
int maxNumberOfBalloons(char * text){
    int charNum[26] = {0};
    char* p = text;
    while(*p != '\0') {
        charNum[*p - 'a']++;
        p++;
    }

    charNum['l'-'a'] = charNum['l'-'a'] / 2;
    charNum['o'-'a'] = charNum['o'-'a'] / 2;

    int ret = charNum['b'-'a'];
    if(ret > charNum['a'-'a']) ret = charNum['a'-'a'];
    if(ret > charNum['l'-'a']) ret = charNum['l'-'a'];
    if(ret > charNum['o'-'a']) ret = charNum['o'-'a'];
    if(ret > charNum['n'-'a']) ret = charNum['n'-'a'];
    
    return ret;
}
```
