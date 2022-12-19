### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;

        for (int i=0; i<(int)s.size()/2; i++)
            swap(s[i], s[(int)s.size()-1-i]);
    }
};
```