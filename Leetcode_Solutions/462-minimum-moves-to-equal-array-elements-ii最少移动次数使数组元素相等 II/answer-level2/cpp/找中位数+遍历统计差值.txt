
我找中位数的方法是直接`O(nlogn)`排序的，然后通过`O(n)`遍历统计差值。
原理嘛...最少移动次数的情况是这样子的：
排序之后，从两边往中间走，最大和最小之间的差距是一定要填补上的，所以不管+1 还是-1，最后都等于中位数。

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 找中位数
        double result=0.0;
        double middleNumber;
        unsigned length=nums.size();
        if(length==1)return 0;
        sort(nums.begin(),nums.end());
        if(length%2==0){
            middleNumber=(nums[length/2]+nums[length/2-1])/2.0;
        }else{
            middleNumber=nums[length/2];
        }
        // 遍历统计差值
        for(unsigned i=0;i<length;i++)
            result+=abs(nums[i]-middleNumber);
        
        return (int)result;
    }
};
```