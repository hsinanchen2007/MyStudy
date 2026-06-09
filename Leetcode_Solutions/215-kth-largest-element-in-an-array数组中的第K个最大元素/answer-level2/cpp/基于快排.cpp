### 解题思路
基于快排，前大后小，第K元素即为TOP K

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if (len==0 || len<k)
        {
            return 0;
        }
        quickSelect(nums,k,0,len-1);
        int res=nums[k-1];
        return res;
    }

    void quickSelect(vector<int>& nums,int k,int i,int j)
    {
        int p=nums[i];
        int left=i;
        int right=j;
        while(left<right)
        {
            while(left<right && nums[right]<=p)
            {
                right--;
            }
            if(left<right)
            {
                nums[left]=nums[right];
            }
            while(left<right && nums[left]>=p)
            {
                left++;
            }
            if(left<right)
            {
                nums[right]=nums[left];
            }
        }
        nums[left]=p;
        if(left+1==k)
        {
            return; 
        }
        else if(left+1<k)
        {
            quickSelect(nums,k,left+1,j);
        }
        else
        {
            quickSelect(nums,k,i,right-1);
        }
    }
};
```