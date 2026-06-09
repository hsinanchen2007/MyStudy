```
int dp(int k, char * s, int left, int right) {
    if (right <= left) return 0;
    if (right - left + 1 < k) return 0; 
    //去重
    int code[26] = {0};
    for (int i = left; i <= right; i++) {
        int pos = s[i] - 'a';
        code[pos]++;
    }
    //状态迁移
    int rst;
    for (int i = left; i <= right; i++) {
        int pos = s[i] - 'a';
        if (code[pos] < k) {
            int rst1 = dp(k,s,left, i-1);
            int rst2 = dp(k,s,i+1, right);
            rst = rst1 > rst2 ? rst1 : rst2;
            return rst;
        }
    }
    rst = right - left + 1;
    return rst;
}

int longestSubstring(char * s, int k){
    int len  = strlen(s);
    if (len == 0 || k > len) return 0;
    if (k < 2) return len;

    int rst = dp(k, s, 0, len -1); 
    return rst;
}
```
