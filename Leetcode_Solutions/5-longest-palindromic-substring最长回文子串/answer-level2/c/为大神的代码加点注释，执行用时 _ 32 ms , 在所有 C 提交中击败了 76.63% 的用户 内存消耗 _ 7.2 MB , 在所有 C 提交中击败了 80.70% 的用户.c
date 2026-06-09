```


char * longestPalindrome(char * s){
    int len = strlen(s);
    int maxSubStrlen = 0; /* 最大子串长度，用于寻找最大字串，并记录子串左右位置 */
    int startIndex = 0; /* 子串起始位置 */
    int endIndex = 0; /* 子串结束位置 */
    int searchIndex = 0; /* 中心扩展法：首先找到中心子串 */
    int SubStrlen = 1; /* 子串的长度，初始值为中心子串1 */
    
    int i,n_start,m_end;
    
    if(len <= 1) {
        return s;
    }
    
    while(searchIndex < len) {
        for(i = searchIndex + 1;i < len;i++) {
            if(s[searchIndex] != s[i]) {
                break;
            }
            /* 如果找到两个字符相同,子串长度加1 */
            SubStrlen++;
        }
        /* 开始扩展 */
        n_start = searchIndex - 1;
        m_end = i; /* i = searchIndex + 1 */
        /* 判断searchIndex两边字符是否相等 */
        while((n_start >= 0)&&(m_end < len)) {
            if(s[n_start] != s[m_end]) {
                break;
            }
            n_start--;
            m_end++;
            
            SubStrlen += 2; /* 如果相等，则子串长度加2 */
        }
        /* 记录最长子串 */
        if(SubStrlen > maxSubStrlen) {
            maxSubStrlen = SubStrlen;
            startIndex = n_start + 1; /* 为何要+1？因为肯定是searchIndex两边的字符不相等，但又n_start--，m_end++，要去掉这部分 */
            endIndex = m_end - 1;
        }
        SubStrlen = 1; /* 子串查找完毕，将子串长度初始化为1 */
        searchIndex++;  
    }
    s[endIndex + 1] = '\0';
    return &s[startIndex];
    
}


```

