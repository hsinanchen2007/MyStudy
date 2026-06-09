#define LEN  128
char* minWindow(char* s, char* t)
{
    //滑动窗口
    //left right指针，遍历被检索字符串
    //每找到一个窗口进行检查，是否是最小匹配串，同时更新left指针
    //窗口移动的推动者，left指针所指向的值，如果匹配则减小窗口
    int sLen = strlen(s), tLen = strlen(t), needsLen = 0;
    int left = 0, right = 0;
    int match = 0;
    int start = 0, minLen = INT_MAX;

    int needs[LEN], windows[LEN];
    memset(needs, 0, sizeof(needs));
    memset(windows, 0, sizeof(windows));

    for(int i = 0; i < tLen; i++){        
        if(needs[t[i]] == 0) { //不同的字符的个数
            needsLen++;
        }
        needs[t[i]]++;
    }
    
    printf("needsLen=%d\r\n", needsLen);

    while(right < sLen) {
        char c1 = s[right];
        if(needs[c1]) {
            windows[c1]++;
            if(needs[c1] == windows[c1]) {
                match++; //某个字符已经匹配够了
            }
        }
        right++;
        while(match == needsLen){
            if((right - left) < minLen) {
                start = left;
                minLen = right - left;
            }
            char c2 = s[left];
            if(needs[c2]) {
                windows[c2]--;
                if(windows[c2] < needs[c2]) {
                    match--;
                }
            }
            left++;
        }
    }

    if(minLen == INT_MAX) 
        return "";
    
    s[start + minLen] = '\0';
    return s + start;
} 