/*

https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together/

1151. 最少交换次数来组合所有的 1

中等
87
company
亚马逊

给出一个二进制数组 data，你需要通过交换位置，将数组中 任何位置 上的 1 组合到一起，并返回所有可能中所需 最少的交换次数。

示例 1:

输入: data = [1,0,1,0,1]
输出: 1
解释: 
有三种可能的方法可以把所有的 1 组合在一起：
[1,1,1,0,0]，交换 1 次；
[0,1,1,1,0]，交换 2 次；
[0,0,1,1,1]，交换 1 次。
所以最少的交换次数为 1。

示例  2:

输入：data = [0,0,0,1,0]
输出：0
解释： 
由于数组中只有一个 1，所以不需要交换。

示例 3:

输入：data = [1,0,1,0,1,0,0,1,1,0,1]
输出：3
解释：
交换 3 次，一种可行的只用 3 次交换的解决方案是 [0,0,0,0,0,1,1,1,1,1,1]。
示例 4:

输入: data = [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
输出: 8 

提示:

1 <= data.length <= 105
data[i] == 0 or 1.

*/

class Solution100 {
public:
    // 2023.2.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-swaps-to-group-all-1s-together.cpp
    // Time:  O(n)
    // Space: O(1)
    int minSwaps(vector<int>& data) {
        const auto& total_count = accumulate(data.cbegin(), data.cend(), 0);
        int result = 0, count = 0, left = 0;
        for (int i = 0; i < data.size(); ++i) {
            count += data[i];
            if (i - left + 1 > total_count) {
                count -= data[left];
                ++left;
            }
            result = max(result, count);
        }
        return total_count - result;
    }
};


class Solution {
public:
    // 2023.2.12, from https://walkccc.me/LeetCode/problems/1151/
    int minSwaps(vector<int>& data) {
        const int k = count(begin(data), end(data), 1);
        int ones = 0;     // Ones in window
        int maxOnes = 0;  // Max ones in window

        for (int i = 0; i < data.size(); ++i) {
            if (i >= k && data[i - k])
                --ones;
            if (data[i])
                ++ones;
            maxOnes = max(maxOnes, ones);
        }

        return k - maxOnes;
    }
};
