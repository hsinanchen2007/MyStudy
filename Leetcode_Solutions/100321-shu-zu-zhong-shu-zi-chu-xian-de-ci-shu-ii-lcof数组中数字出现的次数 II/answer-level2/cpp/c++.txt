### 解题思路
使用 unordered_map
![image.png](https://pic.leetcode-cn.com/452cb13f3d99ea3f8f4c543e82d7c8a6e93ebc0836b0b3c1895efa995a7c162d-image.png)

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]]++; 
        }
        for(auto i:nums){
            if(map[i] == 1) return i;
        }
        return -1;
    }
};
```