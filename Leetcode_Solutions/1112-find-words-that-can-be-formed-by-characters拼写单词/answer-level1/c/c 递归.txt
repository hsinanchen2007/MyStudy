
### 代码

```c
void cntCh(char ** words, int index, int wordsSize, char *chars, int *cnt){
    int charsCnt[256] = {0};
    int chLen = strlen(chars);
    for( int i = 0; i < chLen; i++) {
        charsCnt[chars[i]]++;
    }
    int wordLen = strlen(words[index]);
    for(int i  = 0; i < wordLen; i++ ) {
        if( charsCnt[words[index][i]] > 0 ) {
            charsCnt[words[index][i]]--;
        } else {
            return;
        }
    }
    (*cnt)+=wordLen;
}
int countCharacters(char ** words, int wordsSize, char * chars){
    int cnt = 0;
    for( int i = 0; i < wordsSize; i++ ) {
        cntCh( words, i, wordsSize, chars, &cnt);
    }
    return cnt;
}

```