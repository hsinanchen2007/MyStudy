### 解题思路
![image.png](https://pic.leetcode-cn.com/0a773839576a506b5c6d6368236b45cf9b212843d7e1ff08705e33e6f1f478f6-image.png)
双指针还得多做一点，好好理解什么条件下：
1.右指针移动
2.右指针停止
3.左指针移动
3.左指针停止

### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)
int lengthOfLongestSubstringTwoDistinct(char * s){
    int sLen = strlen(s);
    if ((s == NULL || (sLen == 0))) {
        return 0;
    }

    int charNeeds; /* 统计字符的种类数 */
    int* charMap = (int *)malloc(sizeof(int) * 128); /*  */
    memset(charMap, 0, sizeof(int) * 128);
    int maxLen;

    int leftIdx, rightIdx;

    leftIdx   = 0;
    rightIdx  = 1;
    charNeeds = 1;
    charMap[s[0]]++;
    maxLen = 1;
    while (rightIdx < sLen) {
        if (charMap[s[rightIdx]] == 0) {
            charNeeds++;
        }

       charMap[s[rightIdx]]++;

        if (charNeeds <= 2) {
            maxLen = MAX(maxLen, rightIdx - leftIdx + 1);
        } else {
            while (charNeeds > 2) {
                char ch = s[leftIdx];
                while ((leftIdx < rightIdx) && (s[leftIdx] == ch)) {
                    charMap[ch]--;   
                    leftIdx++;          
                }
                if (charMap[ch] == 0) {
                    charNeeds--;
                }
            }
        }
        rightIdx++;
    }
    return maxLen;
}
```