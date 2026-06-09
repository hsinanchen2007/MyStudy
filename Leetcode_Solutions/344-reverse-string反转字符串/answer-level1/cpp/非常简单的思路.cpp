### 解题思路
很简单的交换

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int n = s.size() / 2;
        int end = s.size()-1;
        for(int i = 0; i < n; ++i)
        {
            swap(s[i], s[end-i]);
        }
    }
};
```