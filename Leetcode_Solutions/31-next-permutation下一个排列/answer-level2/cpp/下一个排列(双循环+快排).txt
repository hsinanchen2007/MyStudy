### 解题思路

### 代码

```cpp
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        bool find=false;

        for(int i=nums.size()-1;i>=0;i--)
        {
            int temp=1<<10,pos=i;

            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i] && nums[j]<temp)
                {
                    temp=nums[j];
                    pos=j;
                    find=true;
                }
            }

            if(find) 
            {
                swap(nums[i],nums[pos]);
                QuickSort(nums,i+1,nums.size()-1);
                return;
            }
        }

        if(!find) QuickSort(nums,0,nums.size()-1);
    }

    //手写快速排序,也可使用c++ sort函数
    void QuickSort(vector<int>& nums,int first,int last)
    {
        if(last-first<1) return;
        int low=first,high=last,key=nums[low];

        while(low!=high)
        {
            while(low!=high && nums[high]>=key) high--;
            nums[low]=nums[high];

            while(low!=high && nums[low]<key) low++;
            nums[high]=nums[low];
        }

        nums[low]=key;

        QuickSort(nums,first,low-1);
        QuickSort(nums,low+1,last);
    }
};
```
![image.png](https://pic.leetcode-cn.com/e9f1fab60486475e192c124d4e3d68ff851875548efb6ca9b854b3e617be53b7-image.png)
