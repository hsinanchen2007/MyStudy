### 解题思路
主要是dfs深度搜索遍历，遍历的时候计算每个区间可能的长度进行校验。

### 代码
![image.png](https://pic.leetcode-cn.com/e5542b0683afbe1664ae5baec4b4f1aaf3bfd41a8edd4fe946e8949ddad9ceec-image.png)

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 100123 -> 10.01.2.3肯定是错误的，只能组合为 100.1.2.3
/* 
思路：每个ip地址，范围在0~255之间，最小为1位数，最大为3位数
暴力法可以在字符串中任意三个位置放入分界符，再判断每一个区间的值是不是在范围内，以及符合要求（除了是0，不能是0开头）。复杂度是O(n^3)
简化思路：从第一个开始判断，找出所有可能性，再往后依次类推，这样比暴力法好一些，还可以通过判断当前区间可取的字符串长度来简化。
以第一个区间为例，计算方式如下：n表示当前剩余的字符数, 减去当前区间后，其他区间的平均值要小于3 并且大于 1
(n - min) / 3 <= 3 ==> min >= n - 9 && min >= 1
(n - max) / 3 >= 1 ==> max <= n - 3 && max <= 3
*/

static int GetMinDigit(int total, int intervalCnt) {
    return (total - 3 * (intervalCnt - 1)) > 1 ? (total - 3 * (intervalCnt - 1)) : 1;
}

static int GetMaxDigit(int total, int intervalCnt) {
    return (total - 1 * (intervalCnt - 1)) < 3 ? (total - 1 * (intervalCnt - 1)) : 3;
}

static int isIP(char *s, int ipLen)
{
    if (ipLen >= 2 && s[0] == '0') {
        return 0;
    }

    if (ipLen == 3 && ((s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0')) > 255) {
        return 0; 
    }
    return 1;
}

#define MAX_ARRAY_SIZE 100
char *g_ipSeq;
int g_returnSize = 0;

static void dfs(char *s, int intervalCnt, int seqShift, char **ipSeqArray)
{
    // s为当前剩余字符串，
    int leftLen = strlen(s);

    if (intervalCnt == 1) {
        if(!isIP(s, leftLen)) {
            return;
        }
        memcpy(g_ipSeq + seqShift, s, leftLen);
        ipSeqArray[g_returnSize] = (char *)calloc(strlen(g_ipSeq) + 1, sizeof(char));
        strcpy(ipSeqArray[g_returnSize], g_ipSeq); // 保存结果
        g_returnSize++; // 更新二维数组宽度
        return;    
    }

    // 关键：根据剩余的字符串长度和区间数量，计算出当前区间可能的取值
    for (int i = GetMinDigit(leftLen, intervalCnt); i <= GetMaxDigit(leftLen, intervalCnt); i++) { 
        if(!isIP(s, i)) {
            return;
        }
        memcpy(g_ipSeq + seqShift, s, i);
        g_ipSeq[seqShift + i] = '.'; // 拼接ip
        dfs(s + i, intervalCnt - 1, seqShift + i + 1, ipSeqArray);
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    char **ipSeqArray = NULL;
    int finalLen = strlen(s) + 3;
    g_ipSeq = (char *)calloc(finalLen + 1, sizeof(char));
    g_ipSeq[finalLen] = '\0';

    ipSeqArray = (char **)calloc(MAX_ARRAY_SIZE, sizeof(char *));
    g_returnSize = 0;
    /* 用深度搜索遍历 */
    dfs(s, 4, 0, ipSeqArray);
    free(g_ipSeq);

    *returnSize = g_returnSize;
    return ipSeqArray;
}
```