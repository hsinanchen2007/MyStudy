### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        //  //本质上是一道数学题
        //设置count = 0，从头开始遍历s 遇到R count++，遇到 L count--
        //当count = 0 时，表示可分割为一个包含相同数量的 'L' 和 'R'的子串
        int count = 0;
        int ans = 0;
        for(char c : s)
        {
            if(c == 'R')
                count++;
            else if(c == 'L')
                count--;
            if(count == 0)
                ans++;
        }
        return ans;
    }
};
```