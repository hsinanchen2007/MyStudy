```
int lengthOfLongestSubstring(char * s){
    int maxRes = 0;
    int tempNum[256] = {0};
    int sIndex = 0;
    int windowStart = 0;
    int newMax = 0;
    while(s[sIndex])
    {
        int *temp = &tempNum[s[sIndex]];
        if(*temp >= (windowStart + 1)) 
        {
            windowStart = *temp;
        }
        newMax = sIndex - windowStart + 1;
        maxRes = maxRes > newMax? maxRes : newMax;
        *temp = sIndex + 1;
        sIndex++;
    }
    return maxRes;
}
```
