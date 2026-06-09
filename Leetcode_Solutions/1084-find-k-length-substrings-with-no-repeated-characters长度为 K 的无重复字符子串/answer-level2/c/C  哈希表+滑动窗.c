哈希表，只有26个小写字母，2个全局变量监控状态，如果遇到map[s[i] - 'a'] == 0，说明是新字母，不同字母个数g_cnt +1，如果这个值已经大于1，那么用另外一个变量
g_dupCnt+1（表示重复字母个数增加），满足条件的子串，应该是g_cnt == K且g_dupCnt == 0。 循环时，平移窗体右边界直到g_cnt==K，然后开始缩减左边界，直到g_dupCnt==0即是1个结果。
需要特别注意的是： 当右边界到达字符串最右端时，左边界还需要继续移动，直到找到最后1个子串，或者字母个数g_cnt已经小于K就直接结束。

执行结果：通过
显示详情
执行用时 : 0 ms, 在所有 C 提交中击败了100.00的用户
内存消耗 : 5.5 MB, 在所有 C 提交中击败了100.00%的用户
```
char g_map[26];
int g_cnt;
int g_dupCnt;
void Init() {
    g_cnt = 0;
    g_dupCnt = 0;
    memset(g_map, 0, 26);
}
int numKLenSubstrNoRepeats(char * S, int K){
    int begin, end, res, len;
    Init();
    if ((S == NULL) || (K > strlen(S))) {
        return 0;
    }
    if (K == 1) {
        return strlen(S);
    }
    begin = 0;
    end = 0;
    res = 0;
    len = strlen(S);
    while (end <= len) {
        if ((g_cnt < K) && (end < len)) {
            if (g_map[S[end] - 'a'] >= 1) {
                g_dupCnt++;
            } else {
                g_cnt++;
            }
            g_map[S[end] - 'a']++;
            end++;
        }
        if ((g_cnt == K) && (g_dupCnt == 0)) {
            res++;
        }
        if (g_cnt >= K) {
            if (g_map[S[begin] - 'a'] > 1) {
                g_dupCnt--;
            } else {
                g_cnt--;
            }
            g_map[S[begin] - 'a']--;
            begin++;
        }
        if ((end == len) && (g_cnt < K)) { /* 后面不可能再有有效结果 */
            break;
        }
    }
    return res;
}
```


