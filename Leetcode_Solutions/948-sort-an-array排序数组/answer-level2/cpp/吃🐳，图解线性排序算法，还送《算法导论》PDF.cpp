// 介绍两种不常见的排序算法————计数排序和基数排序。与堆排、快排相比，各有千秋~

// # 计数排序
// * 时间复杂度 O(N + V)，N为元素个数，V 为元素的取值范围。
// * 空间复杂度 O(V)，借助 hash map 等容器可以变为 O(N)。

// 实现思路，遍历数组 nums, 统计每个数字出现的次数，存储到 count 种。记最小数字为 min，最大数字为 max。 从 min 到 max 枚举, 按 count[i] 将 i 放回 nums。如下图所示：
// ![计数排序.gif](https://pic.leetcode-cn.com/e7ffa855cf9de6226ec7cadec9c235eae5bf08be1f8d64145800d58c53745109-%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F.gif)

// ```
int hashCount[100001] = {0};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());
        for(auto v : nums) {
            hashCount[v+50000]++;
        }
        for(int i = 0; i <= 100000; i++) {
            while(hashCount[i] > 0) {
                hashCount[i] -= 1;
                res.push_back(i-50000);
            }
        }
        return res;
    }
};
// ```
// # 基数排序
// * 时间复杂度 O(N*d), N 为元素个数，d 为数字长度。
// * 空间复杂度 O(N)。

// 首先，对十进制的数来说，我们需要十个 vector 来暂存中间结果，设为 vector<int> vec[10]。

// 其次，与常识相悖的是，基数排序需要从低位开始比较。从个位开始，到十位，百位，直到最高位。

// 算法过程如下：
// 1. 从个位开始枚举位置，直到最高位。
// 2. 枚举nums的所有元素，取出对应位置的数字，设为 v，因为是十进制，所以 v ∈ [0,9]，将当前元素放入 vec[v];
// 3. 清空 nums。
// 4. 从 0 到 9，遍历 vec[i]，将 vec[i] 种的元素依次放入 nums 中。
// 5. 清空 vec。跳转第一步。

// 可以参考下图理解：
// ![基数排序.gif](https://pic.leetcode-cn.com/a4a930c23bc32bfe02fee510bee7ce6345724b919e50aa003c4d56486e814977-%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F.gif)

// ```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0, n = nums.size(); i < n; i++) {
            nums[i] += 50000;
        }
        vector<int> data[2][10];
        for(auto v : nums) {
            data[0][v%10].push_back(v);
        }
        int pre = 1, now = 0;
        for(int i = 1, d = 8, div = 10; i <= d; i++, div *= 10) {
            swap(pre, now);
            for(int j = 0; j < 10; j++) {
                data[now][j].resize(0);
            }
            for(int j = 0; j < 10; j++) {
                for(auto v : data[pre][j]) {
                    data[now][v/div%10].push_back(v);
                }
            }
        }
        int top = 0;
        for(int i = 0; i < 10; i++) {
            for(auto v : data[now][i]) {
                nums[top++] = v - 50000;
            }
        }
        return nums;
    }
};
// ```
//         🐳🐳🐳🐳🐳 我割 🐳🐳🐳🐳🐳
// **如果想了解更多好玩的排序算法，可以参看 《算法导论》 第 6，7，8章节。详细的讲述了堆排序，快速排序与线性时间排序**

// ### 关注公众号 👏 [HelloNebula](https://pic.leetcode-cn.com/f18e68ed2306a147b615407e0b0260900672940df4a2fd9a7f7dc9b91e23e55e.jpg) 👏 回复 “算法导论” 获取下载链接 ~

// **如果感觉对你有帮助，那就反手一个赞吧~b(￣▽￣)d**