/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

/*

https://leetcode.cn/problems/get-equal-substrings-within-budget/

1208. 尽可能使字符串相等

中等
190
company
谷歌 Google
company
微软 Microsoft
company
腾讯

给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。
用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。
如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

示例 1：

输入：s = "abcd", t = "bcdf", maxCost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。

示例 2：

输入：s = "abcd", t = "cdef", maxCost = 3
输出：1
解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。

示例 3：

输入：s = "abcd", t = "acde", maxCost = 0
输出：1
解释：a -> a, cost = 0，字符串未发生变化，所以最大长度为 1。 

提示：

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s 和 t 都只含小写英文字母。

*/

// @lc code=start
class Solution100 {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/3602109/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        for (int i = 0, j = 0, cost = 0; i < s.size(); i ++ ) {
            cost += abs(s[i] - t[i]);
            while (cost > maxCost) {
                cost -= abs(s[j] - t[j]);
                j ++ ;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/1208
    /*
        这道题给了两个字符串s和t，定义了一种 cost，是将 s[i] 变为 t[i] 的花费就是两个字母的 ASCII 码值的差的绝对值。
        现在给了一个最大花费额度 maxCost，问最多可以把s串的多少个连续字母转为t的对应字母，从而使得花费不超过给定的最大
        额度。这里强调了是s的子串，即中间不能有断开，若某个位置 s[i] 和 t[i] 相等，那最好了，花费为0，可以继续延长子串
        的长度。既然是子串，肯定是要连续的字母，那就一个一个的字母的累加，当花费超过给定值了，就将开头的字母去掉，从而
        减少总花费。这道 Medium 的题目其实主要就是考察滑动窗口 Sliding Window，维护一个特定长度的窗口，此时若窗口内的
        总花费小于给定值，则扩大窗口长度，即增加窗口的右边界。而一旦总花费超过给定值了，就要移除窗口最左边的元素，有时
        可能要连续移除多个，所以需要用一个 while 循环，条件是窗口内的总花费大于给定值，且左边界小于等于右边界，然后移除
        左边界的元素，并且左边界自增1。同时别忘了每次都用更新后的窗口长度来更新最终结果 res 即可，参见代码如下：    
    */
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, n = s.size(), cur = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            cur += abs(s[i] - t[i]);
            while (cur > maxCost && start <= i) {
                cur -= abs(s[start] - t[start]);
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/get-equal-substrings-within-budget.cpp
    // Time:  O(n)
    // Space: O(1)
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        for (; right < s.length(); ++right) {
            maxCost -= abs(s[right] - t[right]);
            if (maxCost < 0) {
                maxCost += abs(s[left] - t[left]);
                ++left;
            }
        }
        return right - left;
    }
};


class Solution97 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/1208/
    int equalSubstring(string s, string t, int maxCost) {
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
        maxCost -= abs(s[i] - t[i]);
        if (maxCost < 0)
            maxCost += abs(s[j] - t[j++]);
        }

        return s.length() - j;
    }
};


class Solution96 {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+1208
    // Author: Huahua
    // Solution 1: Binary Search
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    int equalSubstring(string s, string t, int maxCost) {
        const int n = s.length();    
        vector<int> c(n + 1);
        auto cit = begin(c) + 1;
        int ans = 0;
        for (int i = 0; i < n; ++i, ++cit) {
            *cit = c[i] + abs(s[i] - t[i]);      
            int len = cit - lower_bound(begin(c), cit, *cit - maxCost);
            ans = max(ans, len);
        }
        return ans;
    }
};


class Solution {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+1208
    // Author: Huahua
    // Solution 2: Sliding Window
    // Time complexity: O(n)
    // Space complexity: O(1)
    int equalSubstring(string s, string t, int maxCost) {
        const int n = s.length();
        int ans = 0;    
        for (int i = 0, j = 0, cost = 0; i < n && j < n; ++i) {
        while (j < n) {
            int c = abs(s[j] - t[j]);
            if (cost + c > maxCost) break;
            cost += c;
            ++j;
        }
        ans = max(ans, j - i);
        cost -= abs(s[i] - t[i]);
        }
        return ans;
    }
};


// @lc code=end

