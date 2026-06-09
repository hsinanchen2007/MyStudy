### 解题思路
把26进制转换成10进制

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s)
    {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum+=(s[i]-'A'+1)*pow(26,s.size()-i-1);
        }
        return sum;
    }
};
```