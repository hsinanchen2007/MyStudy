### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        //大数乘法
        #define SIZE 300
        char cr[SIZE];
        memset(cr,0,sizeof(char)*SIZE);
        int nSize1=num1.size();
        int nSize2=num2.size();
        if(nSize1<=0||nSize2<=0)
        {
            return "";
        }
        if(num1[0]=='0'||num2[0]=='0')
        {
            return "0";
        }
        //把2个字符串进行处理，避免老做减法
        for(int i=0;i<nSize1;++i)
        {
            num1[i]-='0';
        }
        for(int i=0;i<nSize2;++i)
        {
            num2[i]-='0';
        }
        //num1 作为被乘的数
        int nStartIndex=0;
        int nJinWei=0;
        int nResult;
        int nIndex;
        for(int i=nSize2-1;i>=0;--i)
        {
            nJinWei=0;
            nStartIndex=SIZE-(nSize2-i);
            for(int j=nSize1-1;j>=0;--j)
            {
                //num1迭代
                nIndex=nStartIndex-(nSize1-1-j);
                nResult=num1[j]*num2[i]+nJinWei+cr[nIndex];
                if(nResult<10)
                {
                    cr[nIndex]=nResult;
                    nJinWei=0;
                }
                else
                {
                    nJinWei=nResult/10;
                    cr[nIndex]=nResult-10*nJinWei;
                }
            }
            //首部的进位
            if(nJinWei>0)
            {
                cr[nStartIndex-(nSize1)]=nJinWei;
            }
        }
        bool bStart=false;
        string strResult;
        for(int i=SIZE-nSize1-nSize2;i<SIZE;++i)
        {
            if(!bStart&&cr[i]==0)
            {
                continue;
            }
            bStart=true;
            strResult.push_back(cr[i]+'0');
        }
        return strResult;
    }
};
```