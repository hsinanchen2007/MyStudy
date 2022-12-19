### 解题思路
    用一个足够长的数组（桶？）判断是否重复，用窗口判断子串长度，时间复杂度为O(n)

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int arr[128],start=1,maxlen=0,i,end=1;
    char *p=s;
    memset(arr,0,sizeof(arr));
    for(i=0;s[i];i++){
        if(arr[s[i]]<start) arr[s[i]]=end++;
        else{
            if(end-start>maxlen) maxlen=end-start;
            start=arr[s[i]]+1;
            arr[s[i]]=end++;
        }
    }
    if(end-start>maxlen) maxlen=end-start;
    return maxlen;
}
```