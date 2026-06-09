### 解题思路
遍历ransomNote中的元素，若magazine中含此元素，删除之，继续遍历
否则返回false

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(auto s : ransomNote){
            if(magazine.find(s)!=magazine.npos)
                magazine.erase(magazine.find(s),1);
            else
                return false;
        }
        return true;
    }
};
```