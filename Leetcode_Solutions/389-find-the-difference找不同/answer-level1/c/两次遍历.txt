```
char findTheDifference(char * s, char * t){
    int map[26] = {0};
    int i;
    for(i = 0; s[i] != '\0'; i++)
        map[s[i] - 'a']++;
    for(i = 0; t[i] !='\0'; i++){
        map[t[i] - 'a']--;
        if(map[t[i] - 'a'] == -1)
            return t[i];
    }
    return ;
}
```