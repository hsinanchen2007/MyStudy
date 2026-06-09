### 解题思路
用mid?=nums[mid]判断这个数字出现在数组的左边还是右边，终止条件是begin==end则返回end
注意有情况就是[0,1]它的数是2，也就是begin>end 输出end+1

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0) return -1;
        return half(nums,0,nums.size()-1);
    }
    int half(vector<int>& nums,int begin,int end)
    {
        int mid=(begin+end)/2;
        if(begin>end) return end+1;
        if(mid==nums[mid])//这个数字在数组右边
        {
            begin=mid+1;
        }
        else //mid!=nums[mid]
        {
            if(begin==end) return end;
            else end=mid;
        }
        return half(nums,begin,end);
    }
};
```