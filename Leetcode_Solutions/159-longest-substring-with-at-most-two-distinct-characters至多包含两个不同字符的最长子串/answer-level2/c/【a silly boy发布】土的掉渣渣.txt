![image.png](https://pic.leetcode-cn.com/51ed31e85c8292a1e8e1f0da09c780286e7be2a070036995a5c5802e4da0ded0-image.png)
```
bool HasTwoDifferent(char *s, int start, int end) {
    int differCnt = 0;
    bool startFlag = false;
    int i;
    char tmpA;
    char tmpB;

    tmpA = s[start];
    //printf("tmpA: %c, start: %d. end: %d\n", tmpA, start, end);
    for (i = start + 1; i <= end; i++) {
        if (startFlag == false) {
            //printf("s[i]: %c, tmpA: %c\n", s[i], tmpA);
            if (s[i] != tmpA) {
                tmpB = s[i];
                startFlag = true;
            }
        } else {
            if ((s[i] != tmpA) && (s[i] != tmpB)) {
                //printf("=================1\n");
                return false;
            }
        }
    }

    //printf("=================2\n");
    return true;
}

int lengthOfLongestSubstringTwoDistinct(char * s)
{
    int i;
    int j;
    int start = 0;
    int end = 0;
    bool hasTwoDiffer = false;
    int returnSize = 0;

    if (s == NULL) {
        return 0;
    }
    int sLen = strlen(s);

    if (sLen <= 2) {
        return sLen;
    }

    for (i = 0; i < sLen; i++) {
        for (j = i +1; j < sLen; j++) {
            hasTwoDiffer = HasTwoDifferent(s, i, j);
            if (hasTwoDiffer == true) {
                //printf("i: %d, j: %d\n", i, j);
                if (returnSize < (j - i + 1)) {
                    returnSize =  j - i + 1;
                }
            } else {
                break;
            }
        }
    }

    return returnSize;
}
```
