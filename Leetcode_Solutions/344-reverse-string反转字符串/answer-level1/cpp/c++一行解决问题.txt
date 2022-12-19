### 解题思路
简单的题目，利用两个指针，一个从字符串头开始，一个从字符串尾开始，依次交换对应位置的字符即可。
### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0,j = s.size() - 1;i <= j; ++i, --j) swap(s[i],s[j]);
    }
};
```