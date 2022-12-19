双指针滑动窗口解法，时间复杂度O(N)。
![下载.png](https://pic.leetcode-cn.com/a3df571916a380056cef533171ab59cf9eb5e96815810605d56c68f867aa9ade-%E4%B8%8B%E8%BD%BD.png)

滑动窗口，想象一下，在一个坐标上存在两个指针`begin` 和`i` ，`begin` 代表滑窗的左边框，`i`代表滑窗的右边框。两者通过分别向右滑动，前者能使窗口之间的和减小，后者能使窗口之间的和增大。开始时二者重合，窗口的和就是重合点所在的数。

1. 开始`i`向右滑动，使和变大。
2. 当恰好大于等于s时，记录滑窗所包括的子数组长度ans，若ans已有数值，需判断新值是否小于旧值，若是，更新ans。`begin`向右滑动
3. 判断是否仍大于等于s
4. 若是，重复步骤2，3。若否，转步骤1。直到右边框到达最右边
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0; //滑窗的右边框
        int sum = 0; //窗口间的和
        int begin = 0; //滑窗的左边框
        while(i < nums.size()) //滑窗的右边框不能超出界限
        {
            if(sum + nums[i] < s) //若滑窗之间的和小于s，右边框右移，sum增大
            {
                sum += nums[i];
                ++ i;
            }
            else //若滑窗之间的和大于等于s，左边框右移，sum减小
            {
                if(i - begin < ans) //若当前符合条件的连续子数组比ans内记录的长度更小，则更新ans值
                    ans = i - begin + 1;
                sum = sum - nums[begin];
                ++ begin;
            }
        }
        return ans == INT_MAX? 0:ans;
    }
};
```