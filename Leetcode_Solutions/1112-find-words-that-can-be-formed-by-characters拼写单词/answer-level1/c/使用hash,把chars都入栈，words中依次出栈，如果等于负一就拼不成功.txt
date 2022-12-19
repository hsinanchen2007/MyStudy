```
#define MAPSIZE 128
int countCharacters(char ** words, int wordsSize, char * chars){
    int stack[MAPSIZE] = { 0 };
    int lenchars = strlen(chars);
    if (lenchars == 0 || wordsSize == 0) {
        return 0;
    }
    for (int i = 0; i < lenchars; i++) {
        stack[chars[i] - 'a']++;
    }
    int cpyarr[MAPSIZE] = { 0 };
    int flag = 0;
    int sumcnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        int lenwords = strlen(words[i]);
        memcpy(cpyarr, stack, sizeof(char) * MAPSIZE);
        for (int j = 0; j < lenwords; j++) {
            cpyarr[words[i][j] - 'a']--;
            if (cpyarr[words[i][j] - 'a'] < 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            sumcnt += lenwords;
        } else {
            flag = 0;
        }
    }
    return sumcnt;
}
```
