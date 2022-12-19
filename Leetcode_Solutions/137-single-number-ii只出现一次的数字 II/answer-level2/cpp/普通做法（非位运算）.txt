
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=1;
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]!=nums[i+1])
                if(temp==1) return nums[i];
                else temp=1;
            else temp++;
        return nums[nums.size()-1];
    }
};
```