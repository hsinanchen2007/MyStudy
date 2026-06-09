### 解题思路
首先保证两字符串点的个数相同，在后面补上.0，之后为了处理方便在最后加上点，遍历判断即可。

### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int dotCnt1 = 0, dotCnt2 = 0;
        for(auto ch : version1)
            if(ch == '.')
                dotCnt1++;
        for(auto ch:version2)
            if(ch == '.')
                dotCnt2++;
        if(dotCnt1 > dotCnt2)
        {
            while(dotCnt2 != dotCnt1)
            {
                version2 = version2 + ".0";
                dotCnt2++;
            }
        }
        else if(dotCnt1 < dotCnt2)
        {
            while(dotCnt2 != dotCnt1)
            {
                version1 = version1 + ".0";
                dotCnt1++;
            }
        }
        version1 += ".";
        version2 += ".";
        int index1 = 0, index2 = 0, pre1 = 0, pre2 = 0;
        while((index1 = version1.find(".", index1)) != string::npos && (index2 = version2.find(".", index2)) != string::npos)
        {
            int num1 = stoi(version1.substr(pre1, index1 - pre1));
            int num2 = stoi(version2.substr(pre2, index2 - pre2));
            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            index1++;
            index2++;
            pre1 = index1;
            pre2 = index2;
        }
        return 0;
    }
};
```