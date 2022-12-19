假设一个滑动窗口，窗口内无重复字符，设置左右变量l，r来表示窗口范围，变量值为字符串中字符下标，滑动窗口长为r-l+1,用for循环每次使右变量加1，同时滑动窗口长也加1，每次循环设置变量k来判断窗内是否无重复字符，令k=l，从窗口左边用for循环看窗口内字符是否和窗口最右端字符相同，若相同，则修改左变量值为相同字符的下一个字符的下标，同时修改窗口长度。最后比较当前窗口长和最长子串长，若当前窗口长比最长子串长大，则修改最长字串长为当前窗口长

### 代码

```c


int lengthOfLongestSubstring(char *s){
    int l,r,maxlen,curlen,length;
    maxlen=0;
    curlen=0;
    length=strlen(s);
    for(r=0;r<length && length-l>maxlen;r++){
        curlen++;         //右边扩展一位，滑窗长度加1
        for(int k=l;k<r;k++)    //从左边开始，索引是否有与最右边相同的字符，y若有，则将窗口左边移到相同字符的下一个字符
        {
            if(s[k]==s[r]){
                   l=k+1;
                   curlen=r-l+1;
                   break;
                 }
                
            }
        if(maxlen<curlen)
        {
            maxlen=curlen;
        }
        }
    
    return maxlen; 
 }



```