### 解题思路
比较浪费空间的解法，使用map记录每个元素是否存在，存在则返回true，不存在则插入；

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, int> map;
        unordered_map<int, int>::iterator iter;
        for(int num:nums){
            iter=map.find(num);
            if(iter != map.end()) {
                return true;
            } else {
                map[num]=1;
            }
        }
        return false;
    }
};
```