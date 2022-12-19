如果k大于原数组个数的一半，证明反方向swap会更节省时间，看了各位大佬的方法发现是真的多，但好像大概都这样一个思路。
突然想到另一个方法：就是只对元素序数（如0，1，2，3，4，5）进行这种排序，最后可以得到新的序数顺序（如2，1，0，3，4），然后按照这种顺序把原数组的值对应过来就好了，嘻嘻嘻我也有两种方法了
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if(k%nums.size()==0) return;
        // int firstOne = nums[0];
        if(k<nums.size()/2)
        {
            for(vector<int>::size_type i=nums.size()-1; i!=0; i--)
            {
              int tmp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = tmp;
            }
            rotate(nums,--k);
        }
        else
        {
            for(vector<int>::size_type i=1; i!=nums.size(); i++)
            {
              int tmp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = tmp;
            }
            rotate(nums,++k);
        }
};
```