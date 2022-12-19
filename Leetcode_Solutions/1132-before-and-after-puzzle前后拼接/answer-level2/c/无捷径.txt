#define WORDLEN 101
#define PHRASELEN 200
void GetHeadTail(char *phrase, char *head, char *tail)
{
    int i = 0;
    int low, high;
    char ch;
    int len = strlen(phrase);
    char *tmp = phrase;
    while ((*tmp != ' ') && (i < len)) {
        head[i++] = *tmp;
        tmp++;
    }
    head[i] = '\0';
    tmp = &phrase[len -1];
    i = 0;
    while ((*tmp != ' ') && (i < len)) {
        tail[i++] = *tmp;
        if (i < len) {
            tmp--;
        }  
    }
    tail[i] = '\0';
    low = 0;
    high = i - 1;
    while (low < high) {
        ch = tail[low];
        tail[low] = tail[high];
        tail[high] = ch;
        low++;
        high--;
    }
    return;
}
void DelDuplicate(char **phrases, int *size)
{
    int i;
    int newStart = 1;
    for (i = 1; i < *size; i++) {
        if (strcmp(phrases[i], phrases[i - 1]) != 0) {
            phrases[newStart++] = phrases[i]; 
        }
    }
    *size = newStart;
    return;
}
int StrCmpFun(const void *a, const void *b)
{
    return (strcmp(*(char **)a, *(char **)b));
}
char ** beforeAndAfterPuzzles(char ** phrases, int phrasesSize, int* returnSize)
{
    int i, j;
    int size;
    char head[WORDLEN];
    char tail[WORDLEN];
    char cmpHead[WORDLEN];
    char cmpTail[WORDLEN];
    char **retVal = NULL;
    int retSize = 0;
    retVal = (char **)malloc(PHRASELEN * sizeof(char *));
    if (retVal == NULL) {
        return NULL;
    }
    for (i = 0; i < phrasesSize; i++) {
        GetHeadTail(phrases[i], head, tail);
        for (j = i + 1; j < phrasesSize; j++) {
            GetHeadTail(phrases[j], cmpHead, cmpTail);
            if (strcmp(tail, cmpHead) == 0) {
                retVal[retSize] = (char *)malloc(PHRASELEN * sizeof(char));
                size = strlen(phrases[i]);
                strcpy(retVal[retSize], phrases[i]);
                strcpy(retVal[retSize] + size - strlen(tail), phrases[j]);
                retSize++;
            }
            if (strcmp(head, cmpTail) == 0) {
                retVal[retSize] = (char *)malloc(PHRASELEN * sizeof(char));
                size = strlen(phrases[j]);
                strcpy(retVal[retSize], phrases[j]);
                strcpy(retVal[retSize] + size - strlen(cmpTail), phrases[i]);
                retSize++;
            }
        }
    }
    if (retSize == 0) {
        *returnSize = retSize;
        return retVal;
    }
    qsort(retVal, retSize, sizeof(char *), StrCmpFun);
    DelDuplicate(retVal, &retSize);
    *returnSize = retSize;
    return retVal;
}