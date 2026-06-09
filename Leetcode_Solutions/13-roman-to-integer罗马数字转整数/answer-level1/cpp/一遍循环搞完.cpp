### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int cha[128];
        memset(cha,0,sizeof(char)*128);
        cha['I']=1;
        cha['V']=5;
        cha['X']=10;
        cha['L']=50;
        cha['C']=100;
        cha['D']=500;
        cha['M']=1000;
        int nSize=s.size();
        int nResult=0;
        if(nSize<=0)
        {
            return 0;
        }
        nResult=cha[s[0]];
        for(int i=1;i<nSize;++i)
        {
            //把4 9 这类的数据抽象成规则了
            nResult+=cha[s[i]];
            if(cha[s[i]]>cha[s[i-1]])
            {
                nResult-=2*cha[s[i-1]];
            }
        }
        return nResult;
    }
};
```
基本双百性能