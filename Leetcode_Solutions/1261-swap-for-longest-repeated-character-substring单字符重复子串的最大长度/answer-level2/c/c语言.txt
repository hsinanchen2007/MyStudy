#define MAX_CHAR_NUM  26
#define MAX_V(a, b)  (a > b) ? a : b
#define MIN_V(a, b)  (a < b) ? a : b
int maxRepOpt1(char * text){
    int i;
    int chLen[MAX_CHAR_NUM] = {0};
    int toLen = 0;
    int maxLen = 0;
    int curLen = 1;
    int flag = 0;
    int left = 0;
    int right = 1;
    char leftVal;
    char *p = text;
    while (*p) {
        chLen[*p - 'a']++;
        toLen++;
        p++;
    }
    p = text;
    for (i = 1; i < toLen; i++) {
        leftVal = *(p + left);
        if (leftVal == *(p + i)) { 
            curLen++;
            curLen = MIN_V(curLen, chLen[leftVal - 'a']);
        } else {
            if (flag) { /* 已替换过一次 */
                curLen = MIN_V(curLen, chLen[leftVal - 'a']);
                maxLen = MAX_V(curLen, maxLen);
                i = right;
                left = right;
                curLen = 1;
                flag = 0;
            } else { /* 没替换过 */
                if (leftVal == *(p + i + 1)) { /* 替换继续 */
                    curLen++;
                    right = i; /* 记录替换位置 */
                    flag = 1;
                } else {
                    curLen++;
                    curLen = MIN_V(curLen, chLen[leftVal - 'a']);
                    maxLen = MAX_V(curLen, maxLen);
                    left = i;
                    curLen = 1;
                    flag = 0;
                }
            }
        }
    }
    maxLen = MAX_V(curLen, maxLen);
    return maxLen;
}