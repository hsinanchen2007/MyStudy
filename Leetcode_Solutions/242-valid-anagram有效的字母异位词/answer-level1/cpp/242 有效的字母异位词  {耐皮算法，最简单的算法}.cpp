### 解题思路
太简单，直接两个排序再比较，但时间复杂度高

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.empty()&&t.empty())
        return true;
        if(s.empty()||t.empty())
        return false;

       sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       return s==t;
    }
};
```