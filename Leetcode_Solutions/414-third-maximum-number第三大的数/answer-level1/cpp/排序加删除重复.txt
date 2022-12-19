### 解题思路
此处撰写解题思路
先排个序
再把相同的删掉
再分情况返回
### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i+1);
                i--;
            }
        }
        if(nums.size()<3)
        return nums[nums.size()-1];
        return nums[nums.size()-3];
    }
};
```