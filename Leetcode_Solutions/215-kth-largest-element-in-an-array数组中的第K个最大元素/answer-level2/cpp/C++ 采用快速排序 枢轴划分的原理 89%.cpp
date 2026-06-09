```
//采用随机生成枢轴 会比较快
//第k大个元素 采用快速排序枢轴划分的思想 但是大的放在枢轴左边 小的放在枢轴右边
//选取第一个元素作为枢轴 然后进行一次划分
//划分后看pivot_index与k-1的关系 
//若pivot_index等于k-1 则返回pivot的值 
//若pivot_index小于k-1 则到枢轴右边找第k大的值 //这里是k不是k-pivot_index 虽然是子划分的第k-pivot_index个元素 但是数组的坐标没有变
//若pivot_index大于k-1 则到枢轴左边找第k大的值
//时间复杂度平均情况可以达到o(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums,0,nums.size()-1,k-1);//第k大的坐标为k-1
    }
    int helper(vector<int>& nums,int low,int high,int k)
    {
        int origin_low=low,origin_high=high;//先暂存最初的头尾
        swap(nums[low+rand()%(high-low+1)],nums[low]);//将随机生成的枢轴换到low中去
        int pivot=nums[low];
        while(low<high)
        {
            while(low<high&&nums[high]<=pivot)high--;
                nums[low]=nums[high];
            while(low<high&&nums[low]>=pivot)low++;
                nums[high]=nums[low];
        }
        nums[low]==pivot;//low即为pivot最终的位置  即为pivot_index
        if(low==k)//为第k大的元素 由于数组是从0开始 
            return pivot;
        else if(low<k)//若第k大的元素在枢轴右边
            return helper(nums,low+1,origin_high,k);
        else//若第k大的元素在枢轴左边
            return helper(nums,origin_low,low-1,k);
    }
};
```
