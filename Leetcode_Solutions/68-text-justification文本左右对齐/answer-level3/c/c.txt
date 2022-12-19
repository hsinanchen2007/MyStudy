```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    *returnSize = 0;
    char** res = malloc(sizeof(char*) * wordsSize);
    int count = 0;
    int fast = 0, last = 0;
    for (int i = 0; i < wordsSize; i++) {
        count += strlen(words[i]);
        last++;
        if (count + last - fast - 1 > maxWidth) {
            res[*returnSize] = malloc(sizeof(char) * (maxWidth + 1));
            memset(res[*returnSize], 0, sizeof(char) * (maxWidth + 1));
            count -= strlen(words[i]);
            last--;
            int num = maxWidth - (count + last - fast - 1);
            if (last - fast > 1) {
                int base = num / (last - fast - 1) + 1;
                int add = num % (last - fast - 1);
                sprintf(res[*returnSize], "%s", words[fast++]);
                while (add > 0) {
                    for (int j = 0; j <= base; j++) {
                        sprintf(res[*returnSize], "%s ", res[*returnSize]);
                    }
                    sprintf(res[*returnSize], "%s%s", res[*returnSize], words[fast++]);
                    add--;
                }
                for (int j = fast; j < last; j++) {
                    for (int k = 0; k < base; k++) {
                        sprintf(res[*returnSize], "%s ", res[*returnSize]);
                    }
                    sprintf(res[*returnSize], "%s%s", res[*returnSize], words[fast++]);
                }
            } else {
                sprintf(res[*returnSize], "%s", words[fast++]);
                for (int i = 0; i < num; i++) {
                    sprintf(res[*returnSize], "%s ", res[*returnSize]);
                }
                if (fast != last) sprintf(res[*returnSize], "%s%s", res[*returnSize], words[last]);
            }
            fast = last;
            last++;
            count = strlen(words[i]);
            (*returnSize)++;
        } else if (count + last - fast - 1 == maxWidth) {
            res[*returnSize] = malloc(sizeof(char) * (maxWidth + 1));
            sprintf(res[*returnSize], "%s", words[fast]);
            for (int j = fast + 1; j < last; j++) {
                sprintf(res[*returnSize], "%s %s", res[*returnSize], words[j]);
            }
            fast = last;
            count = 0;
            (*returnSize)++;
        }
    }
    if (count != 0) {
        res[*returnSize] = malloc(sizeof(char) * (maxWidth + 1));
        memset(res[*returnSize], 0, sizeof(char) * (maxWidth + 1));
        sprintf(res[*returnSize], "%s", words[fast]);
        for (int j = fast + 1; j < last; j++) {
            sprintf(res[*returnSize], "%s %s", res[*returnSize], words[j]);
        }
        for (int i = strlen(res[*returnSize]); i <= maxWidth; i++) {
            res[*returnSize][i] = ' ';
        }
        (*returnSize)++;
    }
    return res;
}
```
