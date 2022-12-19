/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 *
 * [2269] 找到一个数字的 K 美丽值
 */

/*

2269. 找到一个数字的 K 美丽值
一个整数 num 的 k 美丽值定义为 num 中符合以下条件的 子字符串 数目：

子字符串长度为 k 。
子字符串能整除 num 。
给你整数 num 和 k ，请你返回 num 的 k 美丽值。

注意：

允许有 前缀 0 。
0 不能整除任何值。
一个 子字符串 是一个字符串里的连续一段字符序列。
 

示例 1：

输入：num = 240, k = 2
输出：2
解释：以下是 num 里长度为 k 的子字符串：
- "240" 中的 "24" ：24 能整除 240 。
- "240" 中的 "40" ：40 能整除 240 。
所以，k 美丽值为 2 。

示例 2：

输入：num = 430043, k = 2
输出：2
解释：以下是 num 里长度为 k 的子字符串：
- "430043" 中的 "43" ：43 能整除 430043 。
- "430043" 中的 "30" ：30 不能整除 430043 。
- "430043" 中的 "00" ：0 不能整除 430043 。
- "430043" 中的 "04" ：4 不能整除 430043 。
- "430043" 中的 "43" ：43 能整除 430043 。
所以，k 美丽值为 2 。
 

提示：

1 <= num <= 109
1 <= k <= num.length （将 num 视为字符串）
通过次数6,892提交次数10,889

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.19, by Hsinan
    int divisorSubstrings(int num, int k) {
        string tmp = std::to_string(num);
        int ans = 0;
        int start = 0;
        for (int end = 0; end < tmp.size(); end++) {
            if (end - start + 1 == k) {
                string window;
                for (int j = start; j <= end; j++) {
                    window = window + tmp[j];
                }
                int divisor = stoi(window);
                if (divisor > 0 && num % divisor == 0) ans++;
                start++;
            }
        }
        return ans;
    }
};


class Solution99 {
public:
    // 2022.8.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-the-k-beauty-of-a-number.cpp
    // Time:  O(logn)
    // Space: O(logn)
    // sliding window
    int divisorSubstrings(int num, int k) {
        int result = 0;
        const auto& s = to_string(num);
        const int base = pow(10, k - 1);
        for (int i = 0, curr = 0; i < size(s); ++i) {
            if (i - k >= 0) {
                curr -= (s[i - k] - '0') * base;
            }
            curr = curr * 10 + (s[i] - '0');
            if (i + 1 >= k) {
                result += static_cast<int>(curr && num % curr == 0);
            }
        }
        return result;
    }
};


class Solution98 {
public:
    // 2022.8.19, from https://walkccc.me/LeetCode/problems/2269/
    // Time: O(n)
    // Space: O(k)
    int divisorSubstrings(int num, int k) {
        const string s = to_string(num);
        int ans = 0;

        for (int i = 0; i + k <= s.length(); ++i) {
            const int x = stoi(s.substr(i, k));
            if (x != 0 && num % x == 0)
                ++ans;
        }

        return ans;
    }
};


class Solution {
public:
    // 2022.8.19, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/2001-2500/2269-Find-the-K-Beauty-of-a-Number/cpp-2269/main.cpp
    // Brute Force
    // Time Complexity: O(n * k)
    // Space Complexity: O(k)
    int divisorSubstrings(int num, int k) {

        string num_s = to_string(num);
        int res = 0;
        for(int i = 0; i + k - 1 < num_s.size(); i ++){
            int x = atoi(num_s.substr(i, k).c_str());
            if(x) res += num % x == 0;
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

