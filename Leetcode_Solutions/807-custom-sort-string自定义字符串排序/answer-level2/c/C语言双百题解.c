把26个字母作为数组的下标，遍历T统计各字母的数量。遍历S中存在的字母按数量依次输出，最后再追加上不存在的字母即可。

char * customSortString(char * S, char * T){
    int lenS = 0;
    int lenT = 0;
    int num[26] = {0};
    char hit[26] = {0};
    int k = 0;
    if ((S == NULL) || (T == S)) {
        return T;
    }

    lenS = strlen(S);
    lenT = strlen(T);

    char* retString = (char*)malloc((lenT + 1) * sizeof(char));
    if (retString == NULL) {
        return NULL;
    }

    for (int i = 0; i < lenT; i++) {
        num[T[i] - 'a'] = num[T[i] - 'a'] + 1;
    }

    for (int i = 0; i < lenS; i++) {
        if (num[S[i] - 'a'] != 0) {
            hit[S[i] - 'a'] = 1;
            for (int j = 0; j < num[S[i] - 'a']; j++) {
                retString[k++] = S[i];
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if ((num[i] != 0) && (hit[i] == 0)) {
            for (int j = 0; j < num[i]; j++) {
                retString[k++] = ('a' + i);
            }
        }
    }

    retString[k] = '\0';

    return retString;
}