```
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    *returnSize = 0;
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    int i, n, spaces, spacenum, extraspace;
    int curr = 0;   // current width
    int start = 0;  // starting words index of current line
    for (i = 0; i < wordsSize; ++i) {
        if (curr + strlen(words[i]) <= maxWidth) {
            curr += strlen(words[i]) + 1;
        } else {
            n = i - start;                 // number of words at current line
            spaces = maxWidth - curr + n;  //space count
            if (n > 1) {
                spacenum = spaces / (n - 1);    // least spaces between words
                extraspace = spaces % (n - 1);  // extra space count
            } else {
                spacenum = spaces;
                extraspace = 0;
            }
            res[*returnSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
            res[*returnSize][0] = '\0';
            for (int j = 0; j < n; ++j) {
                strcat(res[*returnSize], words[j + start]);
                if (n == 1 || j < n - 1) {
                    for (int k = 0; k < spacenum; ++k) {
                        strcat(res[*returnSize], " ");
                    }
                    if (j < extraspace) strcat(res[*returnSize], " ");
                }
            }
            ++(*returnSize);
            start = i;
            curr = strlen(words[i]) + 1;
        }
    }
    // last line
    n = i - start;
    res[*returnSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
    res[*returnSize][0] = '\0';
    strcat(res[*returnSize], words[start]);
    for (i = start + 1; i < wordsSize; ++i) {
        strcat(res[*returnSize], " ");
        strcat(res[*returnSize], words[i]);
    }
    for (i = strlen(res[*returnSize]); i < maxWidth; ++i) {
        res[*returnSize][i] = ' ';
    }
    res[(*returnSize)++][maxWidth] = '\0';
    return res;
}
```
