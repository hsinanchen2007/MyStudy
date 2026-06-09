static bool isValid(char * S){

    unsigned int len = strlen(S);
    int top = -1;
    int i;
    char* pstk = NULL;
    if (S == NULL || len <= 0) {
        return  false;
    }

    pstk = (char*)malloc(sizeof(char) * len);
    (void)memset(pstk, 0, sizeof(char) * len);

    for (i = 0; i < len; i++) {
        switch (S[i]) {
            case 'a':
            case 'b':
                pstk[++top] = S[i];
                break;
            case 'c':
                if (top < 1) {
                    return false;
                }
                if (pstk[top] == 'b' && pstk[top - 1] == 'a') {
                    top -= 2;
                } else {
                    pstk[++top] = S[i];
                }
                break;
            default:
                break;

        }
    }

    if (top < 0) {
        return true;
    }
    return false;
}