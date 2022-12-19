### 解题思路
初看这道题目时，一脸懵逼，完全不懂题目要做什么！！！
分析题目：
根据题意“下一个排列”即为这个序列所代表的数比题目给定的原序列(数)大，且又是在比原序列(数)大的所有序列中最小的序列。当然，如果一个序列是降序则不存在下一个排列，原因是这个序列所代表的数已经最大了，没有比其小的数了，完全倒置得到最小数返回即可。
算法步骤：
step1：我们对数组nums从后往前迭代比较，查找第一个相邻元素i和i-1，使得nums[i-1] < nums[i]，即找到第一个递减的数nums[i-1]
step2：在nums数组中，从i开始往后查找最后一个比nums[i-1]大的数nums[j](其中nums[j]为i后面子序列中最小的比nums[i-1]大的数)
step3：交换nums[i]和nums[j]，即swap(nums[i], nums[j]);
step4：升序排序nums数组中从i到数组末尾的元素，即sort(nums.begin() + i + 1, nums.end());原因是获得满足条件的最小子排列。

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = nums.size() - 1; j != i; j--)
            {
                if(nums[i] < nums[j])
                {
                swap(nums[i], nums[j]);
                sort(nums.begin() + i + 1, nums.end());
                return;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};
```