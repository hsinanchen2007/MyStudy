### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int k = 0, sum = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R') k++;
            else k--;
            if(k == 0) sum++;
        }
        return sum;
    }
};
```