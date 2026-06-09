// # 5376. 非递增顺序的最小子序列
// 将数组 nums 划分为两个子序列 A, B，A 要满足下述两个条件：
// * sum(A) > sum(B)
// * A 的长度要尽可能的短。

// 当把 nums 中的所有元素都给 A 时，显然满足第一个条件，因为 nums 中只有正整数。
// **然后不断的将 A 中最小的元素转移到 B 中，直到无法转移**。无法转移的意思是，再转移一个元素就会打破第一条限制。此时 降序排序的 A 即为答案。
// 实现代码如下：

// ```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0; 
        for(auto v : nums) {
            sum += v;
        }
        int ts = 0;
        for(int i = 0; i < nums.size(); i++) {
            ts += nums[i];
            if(ts > sum - ts) {
                return vector<int>(nums.begin(), nums.begin() + i + 1);
            }
        }
        return nums;
    }
};
// ```
// # 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
// * **分享周赛题解**
// * **分享计算机专业课知识**
// * **分享C++相关岗位面试题**
// * **分享专业书籍PDF**
