```
int lengthOfLongestSubstring(char * s){
    int len=strlen(s);
    if(len==0)return 0;
    int start=0,end=0;
    int flag[260]={0};
    int maxlen=0;
    while(end<len){
        int idx=s[end];
        if(flag[idx]==0){//没重复，就end++
            flag[idx]=1;
            end++;
            maxlen=maxlen>(end-start)?maxlen:(end-start);
        }
        else {
            int idx=s[start];//出现重复，start++, 缩小窗口
            flag[idx]=0;
            start++;
        }
    }
    return maxlen;
}
```
