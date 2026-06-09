int countCharacters(char ** words, int wordsSize, char * chars){
    
    int result = 0;
    int **hashWords = (int **)calloc(wordsSize, sizeof(int *));
    if(words == NULL || chars == NULL || hashWords == NULL)
        return -1;

    int *hashChars = (int *)calloc(26, sizeof(int));
    int lenChars = strlen(chars);
    for(int i = 0;i < lenChars;i++)
        hashChars[chars[i] - 'a']++;

    for(int i = 0;i < wordsSize;i++)
        hashWords[i] = calloc(26, sizeof(int));

    for(int i = 0;i < wordsSize;i++) {
        int j = 0;
        char *p = words[i];
        int lenWords = strlen(p);

        for(int k = 0;k < lenWords;k++)
            hashWords[i][words[i][k] - 'a']++;
        for(j = 0;j < lenWords;j++) {
            if(hashWords[i][words[i][j] - 'a'] > hashChars[words[i][j] - 'a'])
               break;
        }
        if(j == lenWords)
            result += lenWords;
    }

    return result;
}