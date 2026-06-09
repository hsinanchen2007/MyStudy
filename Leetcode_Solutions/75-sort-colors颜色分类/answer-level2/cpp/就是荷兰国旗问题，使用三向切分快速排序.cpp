```
代码块class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        //初始定义zero为最左端多一格,one为0,two为最右端多一格
        //定义这三个参数使得0在左端，1在中间，2在右端
        int zero = -1, one = 0, two = nums.size();
        while(one < two)  //用one右移,two左移遍历整个链表,当相遇时,表示已经遍历完了
        {
            if(nums[one] == 0)  //当其为0时,只需右移一位zero,与nums[one]交换,使得右边的0换到左边,或者是0和0的交换（无所谓）
            {
                swap(nums[++zero], nums[one++]);
            }
            else if(nums[one] == 2)   //当其为2时,只需左移一位two,与nums[one]交换，使得左边的2换到右边
            {
                swap(nums[--two], nums[one]);
            }
            else  //当nums[one]为1时,只需one右移
            {
                one++;
            }
        }
    }
};
```
注：可能语言表达不清，但已经尽力说明白了，愿谅解~