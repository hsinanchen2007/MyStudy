### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        int s=nums.size();
        if(s==1)
        return nums;
        else if(s==2)
        {
            if(nums[0]<=nums[1])
            return nums;
            else 
            {
                int temp=nums[0];
                nums[0]=nums[1];
                nums[1]=temp;
                return nums;
            }
        }
        else
        {
            quicksort(nums,0,s-1);
            return nums;
        }

    }

    void quicksort(vector<int>&nums,int l,int r)
    {
        if (l < r)
        {
		    int i = selectdig(nums, l, r);//先成挖坑填数法调整nums
		    quicksort(nums, l, i - 1); // 递归调用 
		    quicksort(nums, i + 1, r);
	    }
    }

    int selectdig(vector<int>&nums,int i,int j)
    {
        int s=nums.size();
        int temp=nums[i];

        while(i<j)
        {
            while(i<j&&nums[j]>=temp)
            j--;
            if(i<j)
            {
                nums[i]=nums[j];
                i++;
            }
            while(i<j&&nums[i]<temp)
            i++;
            if(i<j)
            {
                nums[j]=nums[i];
                j--;
            }

        }
        nums[i]=temp;
        return i;
    }
};
```