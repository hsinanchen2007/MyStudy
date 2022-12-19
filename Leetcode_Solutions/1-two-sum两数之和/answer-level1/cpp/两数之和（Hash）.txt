### 解题思路
使用一个哈希表存下每一个元素的index，对每一个元素扫描一遍，用target减去这个元素。然后查找剩下的这个元素是否在哈希表里，若在哈希表中则代表查找成功，时间复杂度降为O(N)
用count可以实现查找若返回true即可证明找到这个元素
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indies;
        for(int i = 0; i < nums.size(); i++){
            indies[nums[i]] = i;  
        }
        for(int i = 0; i < nums.size(); i++){
            int left = target - nums[i];
            if(indies.count(left) && indies[left] != i){
                return {i, indies[left]};
            }
        }
        return {};
    }
};
```