### 解题思路
每隔(2 * numRows - 2)一个循环，第二个数是第二个循环的头减去第几行

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        const int& nLen = s.length();
        if(nLen <= numRows)
            return s;
        int nCount = 2 * numRows - 2;
        int nLines = (nLen - 1) / nCount + 1;

        string strResult = "";
        for(int i=0;i<numRows; ++i){
            for(int j=0; j<nLines; ++j){
                //加第一个字母
                int nIndex = (j * nCount) + i;
                if(nIndex < nLen)
                    strResult += s[nIndex];

                //加斜线上面的字母
                if(i != 0 && i != numRows - 1){
                    nIndex = (j + 1) * nCount - i; 
                    if(nIndex < nLen)
                        strResult += s[nIndex];
                }
            }
        }

        return strResult;
    }
};
```