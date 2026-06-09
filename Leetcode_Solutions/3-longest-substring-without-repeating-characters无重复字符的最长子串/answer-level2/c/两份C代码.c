### 解题思路
放上第一次写的代码和优化后的代码, 优化后的代码0ms, 5.6MB

### 代码
```c
// 此代码中的dp[i]其实是不必要的, 因为计算dp[i]时只需要dp[i-1]即可
int lengthOfLongestSubstring(char * s){
    int size = strlen(s);
    if(size == 0){
        return 0;
    }
    int dp[size], idx[256];          // dp[i]是以s[i]结尾的最长非重复子串长度
    memset(idx, -1, sizeof(idx));    // idx[c]用于记录字符c最后出现的位置
    dp[0] = 1, idx[s[0]] = 0;
    for(int i = 1; i < size; i ++){
        int pre_start_idx = i - 1 - dp[i - 1];
        dp[i] = idx[s[i]] > pre_start_idx ? dp[i] = i - idx[s[i]] : dp[i - 1] + 1;
    ¦   idx[s[i]] = i; 
    }
    int ans = 0;
    for(int i=0; i < size; i ++){
        ans = dp[i] > ans ? dp[i] : ans;
    }
    return ans;
}

```

```c
#define max(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char * s){
    int size = strlen(s), pre_idx = -1, ans = 0;
    int idx[256];  // idx[c]用于记录字符c最后出现的位置
    memset(idx, -1, sizeof(idx));
    for(int i = 0; i < size; i ++){
        pre_idx = max(idx[s[i]], pre_idx);  // pre_idx用于记录以s[i-1]结尾的最长非重复子串的起始位置
        ans = max(ans, i - pre_idx);
        idx[s[i]] = i;
    }
    return ans;
}

```