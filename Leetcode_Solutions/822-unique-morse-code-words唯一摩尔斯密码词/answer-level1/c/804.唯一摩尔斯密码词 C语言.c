```
int uniqueMorseRepresentations(char ** words, int wordsSize){
    char mobMap[26][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char **tmp = (char **)calloc(wordsSize,sizeof(char*));

    for (int i = 0; i<wordsSize;i++) {
        tmp[i] = (char *)calloc(60,sizeof(char));
    }
    int k;
    for (int i = 0; i < wordsSize; i++) {
        k = 0;
        int wlen = strlen(words[i]);
        while(k < wlen) {
            strcat(tmp[i],mobMap[words[i][k] - 'a']);
            k++;
        }
    }
    int count = 0;
    int flag[100] = {0};
    for (int i = 0; i < wordsSize; i++) {
        if (flag[i] == 1) {
            continue;
        }
        count++;
        for (int j = i + 1; j < wordsSize; j++) {
            if (strcmp(tmp[i],tmp[j]) == 0) {
                flag[j] = 1;
            }
        }
    }
    for (int i = 0; i<wordsSize;i++) {
        free(tmp[i]);
    }
    free(tmp);
    return count;
}```