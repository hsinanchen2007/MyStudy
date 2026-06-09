### 解题思路
此处撰写解题思路
![784.jpg](https://pic.leetcode-cn.com/57327f0ce4da49dc8fc3cdd84df5c93ceb1cf61801413cb7abfe8fcf2df4b672-784.jpg)

### 代码
二进制数对应全排列，也可以用递归法来做
```cpp
//全排列做法？
#include <algorithm>

inline char showUpper(char ch)
{
    if(ch >='a' && ch <= 'z')
        return (ch-'a'+'A');
    else
        return ch;
}
inline char showLower(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return (ch-'A'+'a');
    else
        return ch;
}


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int charCnt = 0;
        vector<string> strVec;
        vector<int> posVec;
        for(string::iterator iteS = S.begin(); iteS != S.end(); ++iteS)
        {
            if(*iteS >='A' && *iteS <='Z' ||*iteS >='a' && *iteS <='z')
            {
                charCnt++;
                posVec.push_back(distance(S.begin(), iteS));
            }
        }

        int cmdNum = 0;
        for(int i = 0; i < charCnt; ++i)
        {
            cmdNum <<= 1;
            cmdNum ^=1;
        }

        for(int i = 0; i <= cmdNum; ++i)
        {
            int n = i;
            string tmpStr = S;
            //1大写，0小写
            int posNum = 0;
            for(int j = 0; j < charCnt; ++j)    //while为0的按位没有确定位数的按位循环好
            {
                if(n%2 == 1)
                {
                    tmpStr[posVec[posNum]] = showUpper(tmpStr[posVec[posNum]]);
                }
                else
                {
                    tmpStr[posVec[posNum]] = showLower(tmpStr[posVec[posNum]]);
                }
                posNum++;
                n /= 2;
            }
            strVec.push_back(tmpStr);
        }

        return strVec;
    }
};






```