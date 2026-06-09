求下一个更大字典序的排列，也就意味着将nums数组中后面较大的数据和前面较小的数据交换（排除数组已经是字典序最大的这种情况），这样就可以得到更大的字典序排列了，但是如何保证交换完的数据就是下一个更大字典序的排列呢？很简单，只需要从后向前遍历nums数组（i = nums.size() - 1 ---> 0），每次(j = nums.size() - 1 ---> i - 1),查找第一个满足nums[i] < nums[j]的数据，然后swap(nums[i],nums[j])，然后将nums[i + 1] ... nums.end()数据从小到大排序即可。

最坏时间复杂度o(n^2)
空间复杂度o(1)
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        int len = nums.size();
        bool flag = true;
        for(int i = len - 2; i >= 0; i --) {
            for(int j = len - 1; j > i; j --) {
                if(nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }
        if(flag) sort(nums.begin(), nums.end());
    }
};
```

