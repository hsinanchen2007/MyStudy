### 解题思路
在头文件algorithm里，本质也是二分查找

### 代码

```cpp
class Solution {
public:
    int findString(vector<string>& words, string s)
    {
        auto it = find(words.begin(), words.end(), s);
        if (it != words.end()) return it - words.begin();
        else return -1;
    }
};
```