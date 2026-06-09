就是第一次就在o(n^2)的时间复杂度内完成了这个题目。其实也就是一个循环打桩，然后内层的数据进行双指针查找，注意利用一下数值相等的条件进行减枝
![leetcode-9.jpg](https://pic.leetcode-cn.com/808929accb95a96898f8f8f30a056ae18dc03246f74902365da090a72e458cea-leetcode-9.jpg)
题目解法也很类似三数之和。

```c++
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0, len = nums.size();
        for(int pos = 0; pos < len - 2; pos++){
            int j = len - 1, i = pos+1;
            while(i < j){
                int t = nums[i] + nums[j] + nums[pos];
                if(t >= target){
                    while(i < j && nums[j] == nums[--j]);
                } else if(t < target) {
                    res += j - i;
                    while(i < j && nums[i] == nums[++i]) res += j-i;
                }
            }
        }
        return res;
    }
};
```