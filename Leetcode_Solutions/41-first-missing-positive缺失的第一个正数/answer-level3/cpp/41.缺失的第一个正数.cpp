三趟结束。
<1>.将不可能为返回结果的0和负数，置为同样不可能为返回结果的数字，比如len+2；
<2>.将有可能为返回结果的数字（1-len），绝对值减1之后作为下标，置对应位置的数字为负数。（这就是第一步清理负数的原因）
<3>最后一趟，找到第一个还是正数的位置pos，返回pos+1；如果没找到，那就返回len+1；

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int pos=0;
        int len=nums.size();
        //第一趟，清理0和负数
        while(pos < len)
        {
            if(nums[pos]<=0)
                nums[pos]=len+2;
            ++pos;
        }
        //第二趟，处理绝对值在1-len之间的数字。（在处理过程中会再次出现负数）
        pos=0;
        while(pos < len)
        {
            if(nums[pos] <=len && nums[pos] +len >=0 )
                nums[abs(nums[pos])-1]=-abs(nums[abs(nums[pos])-1]);
            ++pos;
        }
        //第三趟，找到第一个还是正数的位置pos，返回pos+1
        pos=0;
        while(pos < len)
        {
            if(nums[pos]>0)
                return pos+1;
            ++pos;
        }
        return len+1;
    }
};
```