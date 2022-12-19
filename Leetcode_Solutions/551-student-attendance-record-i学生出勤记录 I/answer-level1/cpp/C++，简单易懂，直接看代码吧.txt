### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = 0;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == 'A')
                countA++;
            if(s[i] == 'L')
            {
                int currL = 1;
                //计算连续的 'L'的个数
                while(i + 1 < s.size() && s[i] == s[i + 1])
                {
                    currL++;
                    i++;
                }
                countL = max(currL, countL);    //记录最大的连续的'L'的个数          
            }
            i++;
        }
        if(countA <= 1 && countL <= 2)
            return true;
        else 
            return false;
    }
};
```