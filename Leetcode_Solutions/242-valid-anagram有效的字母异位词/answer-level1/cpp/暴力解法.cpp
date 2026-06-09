### 解题思路
先将字符串s t 进行排序
再将排序后的字符串进行比较
### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
```