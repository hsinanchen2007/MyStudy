### 解题思路
双指针在使用时，右指针停止的条件和左指针左移的规则，总是想不好，这道题虽然纯是自己做出来的，但是感觉花费的时间还是比较长。对这类题目有没有哪位小伙伴有好的通用的思路

### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)
int equalSubstring(char * s, char * t, int maxCost){
    /* 输入有效性判断 */
    if ((s == NULL) || (maxCost < 0)) {
        return 0;
    }

    int sLen = strlen(s);
    int* costArr = (int *)malloc(sizeof(int) * sLen);

    int idx, leftIdx, rightIdx;
    int maxLen = 0;
    int resCost = maxCost;
    // printf("maxCost:%d\n", maxCost);
    for (idx = 0; idx < sLen; idx++) {
        costArr[idx] = abs(s[idx] - t[idx]);
        // printf("%d ", costArr[idx]);
    }
    printf("\n");
    /* 采用双指针查找满足要求的子字符串的最大长度 */
    leftIdx = 0;   

    while ((leftIdx < sLen) && (costArr[leftIdx] > maxCost)) {
        leftIdx++;
    }

    rightIdx = leftIdx;

    while (rightIdx < sLen) {
        // printf("leftIdx:%d, rightIdx:%d, resCost:%d\n", leftIdx, rightIdx, resCost);
        if (costArr[rightIdx] <= resCost) {
            resCost = resCost - costArr[rightIdx];

            rightIdx++;
            maxLen = MAX(maxLen, rightIdx - leftIdx);
            // printf("maxLen:%d\n", maxLen);
        } else {
            resCost += costArr[leftIdx];
            leftIdx++;
        }
        if (leftIdx > rightIdx)  {
            resCost = maxCost;
            rightIdx = leftIdx;
        }
    }

    return maxLen;
}
```