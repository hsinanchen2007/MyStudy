**思路**
先用结构体数组记录下数组中每一个成员左右**字符**以及**字符连续的长度**
然后遍历数组成员，对每个成员计算其在**换与不换**的情况下所能取到的最长字符，最后返回最大结果即可。

*换与不换的过程中需要判断能不能换，以及用于交换的字符会不会影响原有的长度*
```
typedef struct placeInfo
{
    int leftCnt;
    char leftAlp;
    int rightCnt;
    char rightAlp;
}PLACE_INFO;

void GetInfo(char *text, PLACE_INFO *info)      // 记录数组中每一个成员左右字符即字符连续的长度
{
    int len = strlen(text);
    info[0].leftCnt = 0;
    info[0].leftAlp = '1';
    info[len - 1].rightCnt = 0;
    info[len - 1].rightAlp = '1';
    int tmpCnt = 1;
    for (int i = 1; i < len; i++) {
        info[i].leftCnt = tmpCnt;
        info[i].leftAlp = text[i - 1];
        if (text[i] == text[i - 1]) {
            tmpCnt++;
        } else {
            tmpCnt = 1;
        }
    }
    tmpCnt = 1;
    for (int j = len - 2; j >= 0; j--) {
        info[j].rightCnt = tmpCnt;
        info[j].rightAlp = text[j + 1];
        if (text[j] == text[j + 1]) {
            tmpCnt++;
        } else {
            tmpCnt = 1;
        }
    }
}

int CalcLen(char *text, PLACE_INFO info, int len, int i)  // 记录第i个字符换或不换的情况下最长的连续字符个数
{
    if (info.leftAlp == text[i] && info.rightAlp == text[i]) {
        return info.leftCnt + 1 + info.rightCnt;
    } else if (info.leftAlp == info.rightAlp && info.leftAlp != text[i]) {
        /* 通过地址大小判断有无换的可能 */
        if (strchr(text, info.leftAlp) != &text[i] - info.leftCnt ||
            strchr(text + i + info.rightCnt + sizeof(char), info.rightAlp) != NULL) {
                return info.leftCnt + 1 + info.rightCnt;
        } else {
            return info.leftCnt + info.rightCnt;
        }
    } 
     else if (info.leftAlp != info.rightAlp) {
        if (info.leftAlp == text[i]) {
            int right = info.rightCnt;
            if (strchr(text, info.rightAlp) != &text[i] + sizeof(char) ||
                strchr(text + i + info.rightCnt + sizeof(char), info.rightAlp)) {
                    right += 1;
                }
            return ((info.leftCnt + 1) > right) ? (info.leftCnt + 1) : right;
        } else if (info.rightAlp == text[i]) {
            int left =  info.leftCnt;
            if (strchr(text, info.leftAlp) != &text[i] - info.leftCnt ||
                strchr(text + i + sizeof(char), info.leftAlp) != NULL) {
                    left += 1;
                }
            return (info.leftCnt > (info.rightCnt + 1)) ? info.leftCnt : (info.rightCnt + 1);
        } else {
            if (strchr(text, info.leftAlp) != &text[i] - info.leftCnt ||
                strchr(text + i + sizeof(char), info.leftAlp) != NULL) {
                return ((info.leftCnt + 1) > info.rightCnt) ? (info.leftCnt + 1) : info.rightCnt;
            } else if (strchr(text, info.rightAlp) != &text[i] + sizeof(char) ||
                strchr(text + i + info.rightCnt + sizeof(char), info.rightAlp) != NULL) {
                return (info.leftCnt > (info.rightCnt + 1)) ? info.leftCnt : (info.rightCnt + 1);
            } else {
                return (info.leftCnt > info.rightCnt) ? info.leftCnt : info.rightCnt;
            }
        }
    } 
    return 0;
}

int maxRepOpt1(char * text) {
    int output = 1;
    int len = strlen(text);
    PLACE_INFO *info = (PLACE_INFO *)malloc(len * sizeof(PLACE_INFO));
    memset(info, 0, len * sizeof(PLACE_INFO));
    GetInfo(text, info);
    int out = 1;
    for (int i = 0; i < len; i++) {
        if (info[i].leftCnt + info[i].rightCnt + 1 < out) {
            continue;                                 // 最大可能小于目前已算出来的结果则跳过
        }
        int tmpLen = CalcLen(text, info[i], len, i);  // 计算第i个字符变或不变的最长字符数
        out = tmpLen > out ? tmpLen : out;
    }
    return out;
}
```
