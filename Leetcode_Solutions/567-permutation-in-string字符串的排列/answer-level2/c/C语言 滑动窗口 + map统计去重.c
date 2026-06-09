### 解题思路
此处撰写解题思路

### 代码

```c
#define CHARCTOR_NUM 26
int checkInclusion(char * s1, char * s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 == 0) {
        return true;
    }
    if (len1 > len2) {
        return false;
    }
    int mapSta1[CHARCTOR_NUM] = {0};
    // 获取key出现次数
    for (int i = 0; i < len1; i++) {
        mapSta1[s1[i] - 'a']++;
    }
    // 循环获取窗口字符串出现次数
    for (int i = 0;  i < len2 - len1 + 1; i++) {
        int start = i;
        int end = i + len1;
        int mapSta2[CHARCTOR_NUM] = {0};
        //统计子串
        for (int m = 0; m < len1; m++) {
            mapSta2[s2[start + m] - 'a']++;
        }
        // match
        int flag = 1;
        for (int n = 0; n < CHARCTOR_NUM; n++) {
            if (mapSta2[n] != mapSta1[n]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }

    return false;
}
```