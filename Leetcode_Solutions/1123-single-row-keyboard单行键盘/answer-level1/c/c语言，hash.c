```
int map[26];
int calculateTime(char * keyboard, char * word)
{
    int i, j, len, lastPos, sum;
    len = strlen(word);
    lastPos = 0;
    sum = 0;
    for (i = 0; i < 26; i++) {
        map[keyboard[i] - 'a'] = i;
    }
    for (i = 0; i < len; i++) {
        sum = sum + abs(map[word[i] - 'a'] - lastPos);
        lastPos = map[word[i] - 'a'];
    }
    return sum;
}
```
