### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        //利用set，hash_map
        if(astr.size() == 0)
            return true;
        set<char> sc;
        for(int j = 0; j < astr.size(); ++j)
        {
            if(sc.insert(astr[j]).second == false)
                return false;
            else
                sc.insert(astr[j]);
        }
        return true;
    }
};
```