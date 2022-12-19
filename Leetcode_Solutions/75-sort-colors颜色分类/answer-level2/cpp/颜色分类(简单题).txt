### 解题思路

### 代码

```cpp
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int red=0,white=0,bule=0;
        for(int i:nums) 
        {
            if(i==0) red++;
            else if(i==1) white++;
            else bule++;
        }
        for(int& i:nums) 
        {
            if(red-->0) i=0;
            else if(white-->0) i=1;
            else if(bule-->0) i=2;
        }
    }

    //快速排序(本题不需要,只是写着加深印象)
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

        nums[high]=key;

        QuickSort(nums,first,high-1);
        QuickSort(nums,high+1,last);
    }
};
```