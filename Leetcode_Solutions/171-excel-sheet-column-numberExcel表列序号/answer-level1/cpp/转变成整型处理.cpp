### 解题思路
转变成整型处理

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) 
    {
        int sum = 0;
        for(int i=0;i<=s.size()-1;i++){
            sum += (s[i]-'A'+1)*pow(26,(s.size()-1-i));
        }
        return sum;
    }
};
```