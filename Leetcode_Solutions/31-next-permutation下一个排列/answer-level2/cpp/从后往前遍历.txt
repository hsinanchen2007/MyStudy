### 解题思路
击败了100%的c++用户
从后往前遍历找到第一个nums[i]>nums[i-1]的i
然后从i开始往后遍历大于nums[i-1]的最小的那个，将其于nums[i-1]交换
然后sort(nums.begin()+i,nums.end());
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-1;i>=1;--i)
        {
            if(nums[i]>nums[i-1])
            {
                int minindex=i;
                for(int j=i;j<n;j++)
                {
                    if(nums[j]>nums[i-1]&&nums[j]<nums[minindex])
                    {
                        minindex=j;
                    }
                }
                int temp=nums[minindex];
                nums[minindex]=nums[i-1];
                nums[i-1]=temp;
                break;
            }
        }
        sort(nums.begin()+i,nums.end());
    }
};
```