### 解题思路
使用暴力回溯

### 代码

```c
bool isMatch(char * s, char * p){
    int slen = strlen(s), plen = strlen(p);
    if(plen==0)
        return slen==0?true:false;
    if (slen==0){
        if(plen==1||p[1]!='*')
            return false;
         return isMatch(s,p+2);
    }
    if (p[0] == '.')
    {
        if (plen == 1 || p[1] != '*')
            return isMatch(s + 1, p + 1);
        if(plen==2)
            return true;
        for (int i = slen; i>=0; i--)
        {
            if(isMatch( s+i,p+2))
                return true;
        }
        return false;
    }
    //俩种情况 一种是匹配的一种是*的
    if(plen>=2&&p[1]=='*'){
        int count=0,sindex=0;    
        while (sindex<slen&&s[sindex]==p[0])
        {
            count++;
            sindex++;
        }
        for (int i = count; i>=0; i--)
        {
            if(isMatch( s+i,p+2))
                return true;
        }
        return false;
    }
    else if(s[0]==p[0])
        return isMatch(s+1,p+1);
    return false;
}
```