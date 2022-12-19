/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

/*

https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/

1423. 可获得的最大点数
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
 

示例 1：

输入：cardPoints = [1,2,3,4,5,6,1], k = 3
输出：12
解释：第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可获得点数。
最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。

示例 2：

输入：cardPoints = [2,2,2], k = 2
输出：4
解释：无论你拿起哪两张卡牌，可获得的点数总是 4 。

示例 3：

输入：cardPoints = [9,7,7,9,7,7,9], k = 7
输出：55
解释：你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。

示例 4：

输入：cardPoints = [1,1000,1], k = 1
输出：1
解释：你无法拿到中间那张卡牌，所以可以获得的最大点数为 1 。 

示例 5：

输入：cardPoints = [1,79,80,1,1,1,200,1], k = 3
输出：202
 

提示：

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length
通过次数43,019提交次数77,773

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.19, by Hsinan
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int tmp = maxSum;
        if (k == cardPoints.size()) return maxSum;
        for (int i = k - 2, j = cardPoints.size() - 1; i >= -1 ; i--, j--) {
            tmp = tmp - cardPoints[i + 1] + cardPoints[j];
            maxSum = max(maxSum, tmp);
        }
        return maxSum;
    }
};


class Solution99 {
public:
    // 2022.8.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-points-you-can-obtain-from-cards.cpp
    // Time:  O(n)
    // Space: O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int result = numeric_limits<int>::max(), total = 0, curr = 0, left = 0;
        for (int right = 0; right < cardPoints.size(); ++right) {
            total += cardPoints[right];
            curr += cardPoints[right];
            if (right - left + 1 > cardPoints.size() - k) {
                curr -= cardPoints[left++];
            }
            if (right - left + 1 == cardPoints.size() - k) {
                result = min(result, curr);
            }
        }
        return total - result;
    }
};


class Solution98 {
public:
    // 2022.8.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1423.%20Maximum%20Points%20You%20Can%20Obtain%20from%20Cards
    // OJ: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
    // Author: github.com/lzl124631x
    // Time: O(K)
    // Space: O(1)
    int maxScore(vector<int>& A, int k) {
        int ans = 0, N = A.size(), left = 0, right = 0;
        for (int i = 0; i < k; ++i) right += A[N - i - 1];
        ans = right;
        for (int i = 0; i < k; ++i) {
            left += A[i];
            right -= A[N - k + i];
            ans = max(ans, left + right);
        }
        return ans;
    }
};


class Solution97 {
public:
    // 2022.8.19, from https://walkccc.me/LeetCode/problems/1423/
    // Time: O(n)
    // Space: O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
        const int sum = accumulate(begin(cardPoints), end(cardPoints), 0);
        int windowSum = accumulate(begin(cardPoints), begin(cardPoints) + n - k, 0);
        int ans = sum - windowSum;

        for (int i = 0; i < k; ++i) {
            windowSum -= cardPoints[i];
            windowSum += cardPoints[i + n - k];
            ans = max(ans, sum - windowSum);
        }

        return ans;
    }
};


class Solution96 {
public:
    // 2022.8.19, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1001-1500/1423-Maximum-Points-You-Can-Obtain-from-Cards/cpp-1423/main2.cpp
    // Sliding Window
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == n) return sum;

        int window = 0, l = 0, r = -1, res = 0;
        while(r + 1 < n){
            window += cardPoints[++r];
            if(r - l + 1 == n - k)
                res = max(res, sum - window), window -= cardPoints[l++];
        }
        return res;
    }
};


class Solution {
public:
    // 2022.8.19, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1001-1500/1423-Maximum-Points-You-Can-Obtain-from-Cards/cpp-1423/main.cpp
    // Presum + Postsum
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + cardPoints[i];

        vector<int> postsum(n + 1, 0);
        for(int i = n - 1; i >= 0; i --) postsum[i] = postsum[i + 1] + cardPoints[i];

        int res = 0;
        for(int i = 0; i <= k; i ++)
            res = max(res, presum[i] + postsum[n - (k - i)]);
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

