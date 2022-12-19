### 解题思路
经过三次解答错误，终于通过了，怪不得这个题通过率这么低，提供测试用例的真是个人才啊。
1.找出符合条件的数字字符串，筛掉空格，并且标记一下符号是正号还是负号，开头只能有一个符号，遇到非数字结束。
2.找到字符串之后要把前面多余的数字0去掉，所以遍历了一次。
3.判断是否越界。
4.开始字符串转为数字

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        string tempStr;
        int bMinus = -1;
        for(int i = 0; i < str.size(); i++)
        {
            if(tempStr.empty())
            {
                if(str[i] == ' '  && bMinus == -1)
                {
                    continue;
                }
                if(str[i] == '+' && bMinus == -1)
                {
                    bMinus = 0;
                    continue;
                }
                if(str[i] == '-' && bMinus == -1)
                {
                    bMinus = 1;
                    continue;
                }
            }
            if(str[i] < 48 || str[i] > 57)
                break;

            tempStr += str[i]; 
        }

        if(bMinus == -1)    bMinus = 0;
        if(tempStr.empty())   return 0;
        const int MaxNumSize = 10;
        const string MaxNumString = "2147483648";

        int zeroCount = 0;
        for(int i = 0; i < tempStr.size() -1; i++)
        {
            if(tempStr[i] != '0') break;
            zeroCount++;
        }
        if(zeroCount != 0 && tempStr.size() > 1)
        {
            tempStr = tempStr.erase(0, zeroCount);
        }

        if(tempStr.size() > 10) return bMinus == 1 ? INT_MIN : INT_MAX;
        if(tempStr.size() == 10 && tempStr >= MaxNumString) return bMinus == 1 ? INT_MIN : INT_MAX;
        
        int retVal = 0;
        for(int i = tempStr.size()-1; i >= 0; i--)
        {
            retVal += pow(10, tempStr.size()-1-i) * (tempStr[i] - 48);
        }
        return bMinus == 1? -1*retVal : retVal;
    }
};
```