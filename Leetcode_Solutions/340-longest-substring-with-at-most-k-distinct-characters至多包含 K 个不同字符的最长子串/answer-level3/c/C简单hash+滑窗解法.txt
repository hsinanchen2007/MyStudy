#define LEN 128
int g_cnt[LEN];

int lengthOfLongestSubstringKDistinct(char * s, int k){
    if (s == NULL) {
        return 0;
    }
    
    memset(g_cnt, 0, sizeof(g_cnt));
    
    int start = 0;
    int end = 0;
    int maxLen = 0;
    int diffcnt = 0;
    
    int len = strlen(s);

    while(end < len) {
        if (g_cnt[s[end]] == 0) {
            diffcnt++;
        }

        g_cnt[s[end]]++;

        while (diffcnt > k) {
            g_cnt[s[start]]--;

            if (g_cnt[s[start]] == 0) {
                diffcnt--;
            }

            start++;
        }

        int dis = end - start + 1;
        maxLen = maxLen > dis ? maxLen : dis;
        end++;  
    }
    

    return maxLen;
}

