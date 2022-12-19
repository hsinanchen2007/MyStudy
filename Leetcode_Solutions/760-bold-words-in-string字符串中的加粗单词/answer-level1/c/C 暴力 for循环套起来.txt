char * boldWords(char ** words, int wordsSize, char * S){
    int lenS = strlen(S);
    int mark[500] = {0};
    int lenWord;
    int flag;
    for (int i = 0; i < lenS; i++){
        for (int j = 0; j < wordsSize; j++){
            lenWord = strlen(words[j]);
            flag = 0;
            for (int k = 0; k < lenWord; k++){
                if (i + k >= lenS){
                    flag = 1;
                } else if (words[j][k] != S[i + k]) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                for (int k = 0; k < lenWord; k++){
                    mark[i + k] = 1;
                }
            }
        }
    }
    char * reS = (int *)malloc(sizeof(char)*2000);
    int iMark = 0;
    int iReS = 0;
    flag = 0; 
    while (iMark < lenS){
        if (mark[iMark] == 0 && flag == 0){
            reS[iReS] = S[iMark];
            iReS++;
            iMark++;
        } else if (mark[iMark] == 1 && flag == 0){
            reS[iReS] = '<';
            iReS++;
            reS[iReS] = 'b';
            iReS++;
            reS[iReS] = '>';
            iReS++;
            reS[iReS] = S[iMark];
            iReS++;
            iMark++;
            flag = 1;
        } else if (mark[iMark] == 1 && flag == 1){
            reS[iReS] = S[iMark];
            iReS++;
            iMark++;
        } else if (mark[iMark] == 0 && flag == 1){
            reS[iReS] = '<';
            iReS++;
            reS[iReS] = '/';
            iReS++;
            reS[iReS] = 'b';
            iReS++;
            reS[iReS] = '>';
            iReS++;
            reS[iReS] = S[iMark];
            iReS++;
            iMark++;
            flag = 0;
        }
    }
    if (mark[lenS - 1] == 1){
        reS[iReS] = '<';
        iReS++;
        reS[iReS] = '/';
        iReS++;
        reS[iReS] = 'b';
        iReS++;
        reS[iReS] = '>';
        iReS++;
    }
    reS[iReS] = '\0';
    return reS;
}