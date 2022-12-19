### 解题思路
使用26位数组做哈希结构

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        
        if(astr.size()==0) return true;
        int * record = new int[26]();
        for(auto s:astr){
            if(record[s-'a']!=0) return false;
            record[s-'a']++;
        }
        return true;
    }
};
```