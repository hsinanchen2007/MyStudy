### 解题思路
1.设置一个表示128个字符的Hash数组,初始值均为-1，设置begin为窗口起始位置，
2.每次用所给S数组的符号ASCII码值作为Hash数组的下标，若Hash数组的值为-1或begin值大于Hash数组存放的值，则加大窗口，否则，就把窗口大小缩小，改变begin值
3.每次都要进行是否有连续两个相同字符放在一起的判断，若有，则重置Hash表重新进行（相当于从头开始）

### 代码

```c
int lengthOfLongestSubstring(char * s){ 
    int maxl=1,clen=0;int begin=0;
    int len=strlen(s);int flag=0;
    if(len==0) return 0;
    if(len==1) return 1;
    int hash[128];
    for(int i=0;i<128;i++) hash[i]=-1;
    for(int i=0;i<len;i++){
        int a=s[i];
        if(hash[a]==-1||begin>hash[a]) {
         hash[a]=i;
         clen++;
         if(i+1<len&&s[i+1]==s[i]){
             if(clen>maxl) maxl=clen;
                for(int i=0;i<128;i++) hash[i]=-1;
                 clen=0;begin=i+1;continue;
            }
        }
        else {
            //if(clen>maxl) maxl=clen;
            if(i+1<len&&s[i+1]==s[i]){
                for(int i=0;i<128;i++) hash[i]=-1;
                 clen=0;begin=i+1;continue;
            }
            clen=i-hash[a];
            begin=hash[a]+1;
            hash[a]=i;
        }
        if(clen>maxl) maxl=clen;
    }
    
    return maxl;
}
```