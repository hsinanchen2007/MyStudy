对称思想，当我们对n-1个数都加一的时候，其实就是对一个数-1。
那么题目可以等价为：
给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使1个元素减少 1。
那么经过换算后，问题就变得很简单了：
我们只需要找到最小的数，然后让其他数挨个减少，向最小的数靠拢即可，所以这道题核心代码如下：
```
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minv=INT_MAX;
        for(int i=0;i<nums.size();i++){
            minv=min(minv,nums[i]);
        }
        int result=0;
        for(auto num:nums){
            result+=num-minv;
        }
        return result;
    }
};
```
