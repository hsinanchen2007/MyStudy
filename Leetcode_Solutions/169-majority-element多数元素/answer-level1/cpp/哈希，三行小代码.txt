### 解题思路
遍历一遍数组，一旦数字的统计超过n/2时，就返回该值

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++)if(++m[nums[i]] > nums.size()/2) return nums[i];
        return -1;
    }
};
```