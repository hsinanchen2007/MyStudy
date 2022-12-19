模仿53题的做法，运用贪心算法求解此题。建议大家先去做一下53题再来看这道题，会有更多感悟。
53题采用的贪心算法，是遍历容器，并在每个步骤中更新当前元素，当前元素位置的最大和和迄今为止的最大和。此题也是在遍历的过程中要更新当前元素，当前元素位置的最大乘积和迄今为止的最大乘积。
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result,curmax; // curmax记录当前元素位置的最大乘积，result记录迄今为止的最大乘积。
        result = curmax = nums[0];

        for(int i=1;i<nums.size();i++){
            curmax = max(curmax*nums[i],nums[i]);
            result = max(curmax,result);
        }
        return result;
    }
};
```
然而，这并不足够。以nums=[-2,1,-4]为例，当遍历到nums[2]时，当前元素为-4，上一次遍历得到的curmax为1。易得curmax为1不变，result也为1不变，是否说明子序列的最大乘积为1呢？显然不是。因为(-2)×1×(-4)=8，大于1！
因此，当遍历到达i位置，若该位置的元素为负数，上一次遍历的curmax与之相乘得到的结果，反而会小于min(curmax*nums[i-1],nums[i-1])与之相乘的结果。因为，一个较小的数和一个较大的数乘同一个负数，肯定是较小的数乘负数，得到的结果更大。
我们还需要一个curmin来记录当前元素位置的最小乘积，当前元素为负数时，curmin和curmax交换，再进行运算，以保证curmax一直都是“当前元素位置的最大乘积”。
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result,curmax,curmin;
        result = curmax = curmin = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                int temp = curmax;
                curmax = curmin;
                curmin = temp;
            }
            curmax = max(curmax*nums[i],nums[i]);
            curmin = min(curmin*nums[i],nums[i]);
            result = max(curmax,result);
        }
        return result;
    }
};
```
