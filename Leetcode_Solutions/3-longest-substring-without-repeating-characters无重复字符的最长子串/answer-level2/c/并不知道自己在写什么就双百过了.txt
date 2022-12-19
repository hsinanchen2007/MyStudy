### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int a[128]={0},b[128]={0},h=0,r=0,len=strlen(s),max=1;
    if(len==0) return 0;
    for(int i=0;i<len;i++)
    {
        if(a[s[i]]!=0)
        {
            r=i;
            max=max>(r-h)?max:(r-h);
            h=h>(b[s[i]]+1)?h:(b[s[i]]+1);
        }
        a[s[i]]++;
        b[s[i]]=i;
    }
    max=max>(len-h)?max:(len-h);
    return max;
}
```