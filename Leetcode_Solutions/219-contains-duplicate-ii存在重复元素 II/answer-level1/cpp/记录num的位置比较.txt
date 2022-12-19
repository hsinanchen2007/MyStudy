### 解题思路
使用map记录上一个元素的位置，当再次出现时比较差值与k

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> map;
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int>::iterator iter=map.find(nums[i]);
            if(iter != map.end() && i-map[nums[i]]<=k) return true;
            else map[nums[i]]=i;
        }
        return false;
    }
};
```