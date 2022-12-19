### 解题思路
当前位置左侧的累乘积和右侧的累乘积的累乘
第一次循环是构建每个元素左侧的累乘积
第二次循环是在第一次构建的累乘积基础上实时更新得到，从而额外空间复杂度是O(1)

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<1)
            return (vector<int>)NULL;
        vector<int> res(nums.size(),0);
        res[0]=1;
        //每个元素左侧的累乘积
        for(int i=1;i<nums.size();i++)
        {
            res[i]=nums[i-1]*res[i-1];
        }
        int tmp=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            res[i]=res[i]*tmp;
            tmp=tmp*nums[i];
        }
        return res;
    }
};
```