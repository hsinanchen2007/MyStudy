### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int tar) 
    {
        vector<int> res(2,-1);
        int tail=nums.size()-1;

        //在小于等于tar/2的元素中选择第一个元素下标i, 然后找第二个下标
        for(int i=0;i<=tail && nums[i]<=tar/2;i++)
        {
            int find=BinarySearch(nums,i+1,tail,tar-nums[i]);
            if(find!=-1) res[0]=i+1,res[1]=find+1;
        }

        return res;
    }

    int BinarySearch(vector<int>& nums,int low,int high,int tar)
    {
        while(high>=low)
        {
            int mid=(low+high)/2;

            if(tar==nums[mid]) return mid;
            else if(tar>nums[mid]) low=mid+1;
            else high=mid-1;
        }

        return -1;    
    }
};
```