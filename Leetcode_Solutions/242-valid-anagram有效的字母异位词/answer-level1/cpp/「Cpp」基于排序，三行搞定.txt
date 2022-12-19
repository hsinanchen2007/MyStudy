### 解题思路

使用`C++`，分别对两个字符串进行排序，然后比较是否相同。

优点：代码简洁

缺陷：时间慢

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(), s.end()); //排序s
        sort(t.begin(), t.end()); //排序t
        return s.compare(t) == 0; //比较字符
        
    }
};
```