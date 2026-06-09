### 解题思路
此处撰写解题思路
基本思路就是根据规律，确定每一行的内容
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        string strResult;
        int nLength=s.size();
        strResult.reserve(nLength);
        int n2numRows_2=2*(numRows-1);
        int nnumRows_1=numRows-1;
        int n2numRows_1=2*numRows-1;
        //第一行特殊 一个z型只有1个数字
        {
            int nIndex=0;
            while(nIndex<nLength)
            {
                strResult.push_back(s[nIndex]);
                nIndex+=n2numRows_2;
            }
        }
        //int nRightLen=0;
        for(int i=1;i<nnumRows_1;++i)
        {
            int nIndex=i;
            int nRight=nIndex;
            //nRightLen=2*(numRows-i-1);
            while(nIndex<nLength)
            {
                strResult.push_back(s[nIndex]);
                nRight=nIndex+2*(numRows-i-1);
                if(nRight<nLength)
                {
                    strResult.push_back(s[nRight]);
                }
                nIndex+=n2numRows_2;
            }
            int nPos=n2numRows_1;
        }
        //最后以行也特殊一个z型只有1个数字
        {
            int nIndex=(nnumRows_1);
            while(nIndex<nLength)
            {
                strResult.push_back(s[nIndex]);
                nIndex+=n2numRows_2;
            }
        }
        return strResult;
    }
};
```
每到双百 有点遗憾