### 解题思路
利用unordered_map建立哈希表，当数组中某个元素的个数大于1时立即返回

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(++m[nums[i]]>1) return nums[i];
        }
        return 0;
    }
};
```