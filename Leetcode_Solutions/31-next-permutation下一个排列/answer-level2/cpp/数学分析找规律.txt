### 解题思路
排列问题，首先分析题意，举几个例子就可以清楚了，145532->154235（找到第一个比后一位小的数字，因为要大于现在的数字，所以必须与后面的第一个大于自己的数字交换，看后面例子）135542--3是第一个小雨后面一位的数字，从右往左，2小于3，前移一位，4大于3，所以，4是第一个大于3的数字，将两者交换，由于前面找到3的时候后面就是降序排列，所以交换后依然是，只是将其中一个数字换掉了，但此数字定大于后一位，小于前一位。由于是下一个排列，所以将高位数字换大后，后面的数字重回最小，将后面的降序子序翻转即可。
因此，维持两个指针，index1用来指向第一个小于后一位的数字，index2用来指向第一个大于index1位置的数字，两者交换后，后面的序列翻转即可。

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length=nums.size();
        if(length<2)
            return;
        int index1=length-2;//由于小于后一位，所以index从倒数第二位开始
        int index2=length-1;//这个指向第一个大于index1的数字
        while(index1>=0&&nums[index1]>=nums[index1+1])//找到index1
        {
            index1--;
        }
        if(index1<0)//已经是最大的排列，返回最小排列，直接翻转原数组即可
        {
            reverseNums(nums,0,length-1);
            return;
        }
        while(index2>index1&&nums[index1]>=nums[index2])//找到index2
        {
            index2--;
        }
        swap(nums[index1],nums[index2]);//交换index1和2
        reverseNums(nums,index1+1,length-1);//翻转子串
    }
    void reverseNums(vector<int>& nums,int start,int end)
    {
        while(start<end)
        {
            swap(nums[start++],nums[end--]);
        }
    }
};
```