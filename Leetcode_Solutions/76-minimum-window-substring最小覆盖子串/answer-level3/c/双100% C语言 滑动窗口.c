### 执行结果
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了100.00%的用户
### 解题思路
**滑动窗口的方法**
用两个map表保存字符出现的次数，初始窗口是短串长度，当计数等于短串长度就是满足条件了cnt == len
1.排除特例
2.初始窗口是短串长度，
3.先遍历一遍初始窗口，得到长串中能匹配到短串的字符个数：只要 <= 短串 就是有效计数, 再多就是多余
4.滑动右边界， 只要 <= 短串 就是有效计数 cnt++;
5.cnt == len的时候 要删除多余的无效字符
6.处理完新满足的串记着 cnt-- 左边界右移

### 代码

```c
char * minWindow(char * s, char * t){
    if (s == NULL || t == NULL) {
        return NULL;
    }

    int len = (int)strlen(s);
    int lent = (int)strlen(t);

    char *out = (char *)malloc(len + 1);
    if (out == NULL) {
        return NULL;
    }

    int outLen = 0;
    memset(out, 0, len + 1);
    if (len < lent || lent == 0) {
        return out;
    }

    int map[128] = {0};
    int mapt[128] = {0};
    int cnt = 0;
    /* 1. 初始窗口是短串长度， 先遍历一遍 得到长串中能匹配到短串的字符个数 */
    for (int i = 0; i < lent; i++) {
        mapt[t[i]]++;
        map[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (mapt[i] > 0) {
            /* 临界点，只要 <= 短串 就是有效计数, 再大就是多余的了 */
            cnt += (map[i] >= mapt[i]? mapt[i] : map[i]);
        }
    }

    /* 2. 当计数等于短串长度就是满足条件了 */
    if (cnt == lent) {
        outLen = lent;
        memcpy(out, s, outLen);
        return out;
    }

    /* 3. 滑动窗口 */
    int l = 0;
    int r = lent;
    for (; r < len; r++) {
        if (mapt[s[r]] == 0) {
            continue;
        }

        map[s[r]]++;
        if (map[s[r]] <= mapt[s[r]]) {
            /* 临界点，只要 <= 短串 就是有效计数, 再大就是多余的了 */
            cnt++;
        }

        if (cnt == lent) {
            /* 从左侧开始校验 找到临界点（map[s[l]] == mapt[s[l]]）删除多余数据 */
            while (mapt[s[l]] == 0 || map[s[l]] > mapt[s[l]]) {
                map[s[l++]]--;
            }

            int cpLen = r - l + 1;
            if (outLen == 0 ||  cpLen < outLen) {
                memset(out, 0, len + 1);
                memcpy(out, s + l, cpLen);
                outLen = cpLen;
            }

            /* 临界点 */
            cnt--;
            map[s[l++]]--;
        }
    }

    return out;
}
```