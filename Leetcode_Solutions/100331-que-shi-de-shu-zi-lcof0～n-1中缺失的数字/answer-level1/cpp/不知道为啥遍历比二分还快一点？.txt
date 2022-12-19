### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //遍历
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i)return i;
        return nums.size();
        
        //二分
        /*int left=0,right=nums.size()-1;
        while(1)
        {
            if(nums[left]!=left)return nums[left]-1;
            if(nums[right]==right)return nums[right]+1;
            if(nums[(left+right)/2]!=(left+right)/2)right=(left+right)/2;
            else if(nums[(left+right)/2]==(left+right)/2)left=(left+right)/2;
            if(left+1==right)return right;

        }
        return 0;*/
    }
};
```