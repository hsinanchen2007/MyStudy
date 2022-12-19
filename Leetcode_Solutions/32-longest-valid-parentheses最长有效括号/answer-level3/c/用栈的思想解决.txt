int longestValidParentheses(char * s){
    int stringLen = 0;
    int* charStack = NULL;
    int i = 0;
    int top = 0;
    int maxLen = 0;

    stringLen = strlen(s);

    if (stringLen < 2) {
        return 0;
    }

    charStack = (int*)malloc(sizeof(int) * (stringLen + 1));
    charStack[0] = 0;

    for (i = 1; i <= stringLen; i++) {
        if (s[i - 1] == '(') {
            /*push*/
            top++;
            charStack[top] = i;
        }

        if (s[i - 1] == ')') {
            if ((top != 0) && (s[charStack[top] - 1] == '(')) {
                top--;
                if ((i - charStack[top]) > maxLen) {
                    maxLen = i - charStack[top];
                }
            } else {
                top++;
                charStack[top] = i;
            }
        }
    }

    return maxLen;
}