/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

/*

https://leetcode.cn/problems/grumpy-bookstore-owner/

1052. 爱生气的书店老板

中等
247
company
谷歌 Google

有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，其中 customers[i] 
是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。

在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。

当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。

请你返回 这一天营业下来，最多有多少客户能够感到满意 。
 

示例 1：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
输出：16
解释：书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.

示例 2：

输入：customers = [1], grumpy = [0], minutes = 1
输出：1 

提示：

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 104
0 <= customers[i] <= 1000
grumpy[i] == 0 or 1

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.7, from https://www.acwing.com/activity/content/code/content/2153920/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/2153920/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0;
        int n = customers.size();

        for (int i = 0, s = 0; i < n; i ++ ) {
            s += grumpy[i] * customers[i];
            if (i >= minutes) s -= grumpy[i - minutes] * customers[i - minutes];
            res = max(res, s);
        }

        for (int i = 0; i < n; i ++ )
            res += !grumpy[i] * customers[i];

        return res;
    }
};


class Solution99 {
public:
    // 2023.2.7, by Hsinan, modified to use only one for loop
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0;
        int already = 0;
        int n = customers.size();

        for (int i = 0, s = 0; i < n; i ++ ) {
            s += grumpy[i] * customers[i];
            if (i >= minutes) s -= grumpy[i - minutes] * customers[i - minutes];
            res = max(res, s);
            already += !grumpy[i] * customers[i];
        }

        return already + res;
    }
};


class Solution98 {
public:
    // 2023.2.9, from https://github.com/grandyang/leetcode/issues/1052
    /*
        这道题说是有个脾气暴躁的书店老板，一个月总有那么几天暴躁，他一暴躁，顾客的满意度就直线下降。现在给了一个数组 grumpy，
        说是这个店主在若干分钟内不定时的就会暴躁，对应的时间内书店的客人数量保存在 customers 数组中。但老板有个神奇的方法可以
        使得自己在连续的X分钟内不暴躁，需要合理使用才能使得更多的顾客满意，让返回最大的满意的顾客数量。首先来想，若这个更年期
        老板没有这个神奇的方法（太太乐口服液？），那么暴躁的时间就是固定的，则不暴躁时能满足的客人的数量也是确定的，这个可以提
        前求出来。而使用了神奇配方之后，可以连续X分钟不暴躁，这段时间内原本就不暴躁的区间不会受到影响，即满意的顾客数不会增加。
        只有这段时间内原本暴躁的分钟内，变的不暴躁了，才会增加满意顾客的数量。为了快速的知道X时间段内暴躁时段的顾客人数，需要
        建立一个累加数组，只统计暴躁时间段的顾客人数，放到数组 ones 中。同时用一个变量 sum 来统计所有不暴躁时间段的顾客人数，
        最后只要遍历每个大小为X的窗口，利用 ones 数组来快速得到暴躁时间段的顾客人数，并且加上 sum，用来更新结果 res 即可，参
        见代码如下：
    */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size(), res = 0, sum = 0;
        vector<int> ones(n + 1);
        for (int i = 1; i <= n; ++i) {
            ones[i] += ones[i - 1];
            if (grumpy[i - 1] == 1) {
                ones[i] += customers[i - 1];
            } else {
                sum += customers[i - 1];
            }
        }        
        for (int i = 0; i + X <= n; ++i) {
            res = max(res, sum + ones[i + X] - ones[i]);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.9, from https://github.com/grandyang/leetcode/issues/1052
    /*
        我们还可以写的更加简洁一下，只用一个 for 循环，这里的 sums 数组就相当于上面的 ones 数组，然后直接把不暴躁时间段的顾客人数
        加到结果 res 中。在累加 sums 数组的过程中，用当前最后的那个X大小的窗口来更新 mx，最后将 mx 加到结果 res 中并返回即可，参见
        代码如下：    
    */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0, n = customers.size(), mx = 0;
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i];
            if (grumpy[i] == 0) res += customers[i];
            else sums[i + 1] += customers[i];
            if (i + 1 - X >= 0) mx = max(mx, sums[i + 1] - sums[i + 1 - X]);
        }
        return res + mx;
    }
};


class Solution96 {
public:
    // 2023.2.9, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/grumpy-bookstore-owner.cpp
    // Time:  O(n)
    // Space: O(1)
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int result = 0, max_extra = 0, extra = 0;
        for (int i = 0; i < customers.size(); ++i) {
            result += grumpy[i] ? 0 : customers[i];
            extra += grumpy[i] ? customers[i] : 0;
            if (i >= X) {
                extra -= grumpy[i - X] ? customers[i - X] : 0;
            }
            max_extra = max(max_extra, extra);
        }
        return result + max_extra;
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/grumpy-bookstore-owner/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0, sum = 0;
        for (int i = 0; i < customers.size(); ++i) sum += grumpy[i] == 0 ? customers[i] : 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 1) sum += customers[i];
            if (i >= X && grumpy[i - X] == 1) sum -= customers[i - X];
            if (i >= X - 1) ans = max(ans, sum);
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2023.2.9, from https://walkccc.me/LeetCode/problems/1052/
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satisfied = 0;
        int madeSatisfied = 0;
        int windowSatisfied = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
            else
                windowSatisfied += customers[i];
            if (i >= X && grumpy[i - X] == 1)
                windowSatisfied -= customers[i - X];

            madeSatisfied = max(madeSatisfied, windowSatisfied);
        }

        return satisfied + madeSatisfied;
    }
};


class Solution93 {
public:
    // 2023.2.9, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/1052.Grumpy-Bookstore-Owner/1052.Grumpy-Bookstore-Owner.cpp
    /*
        1052.Grumpy-Bookstore-Owner
        本题的意思是可以给你一个固定长度的滑窗，滑窗内的满意度可以累加（不管是否grumpy）。求某个滑窗位置时，整体满意度的最大值。

        首先算出sum的基本盘，就是在没有滑窗覆盖的情况下，可以得到的满意度之和。

        然后考虑一个长度为X的滑窗内，我们可能可以额外增加一些满意度。滑动窗口每一次移动，会加入一个元素customers[i]，考察它对应的grumpy[i]
        是否是1，是的话那就是额外增加的满意度，需要加入sum。同时也会有一个元素customers[i-X]离开滑窗，同样考察它对应的grumpy[i+X]是否是1，
        是的话我们就要退回额外的满意度，从sum中扣除。

        整个滑动过程中出现的最大sum，就是答案。    
    */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        int sum = 0;
        int n = grumpy.size();
        for (int i=0; i<n; i++)
            if (grumpy[i]==0)
                sum+=customers[i];

        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (grumpy[i]==1)
                sum += customers[i];
            if (i>=X && grumpy[i-X]==1)
                sum -= customers[i-X];
            ret = max(ret, sum);
        }
        return ret;
    }
};


class Solution {
public:
    // Author: Huahua
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {    
        int base = 0;
        int window = 0;
        int best_window = 0;    
        for (int i = 0; i < grumpy.size(); ++i) {
            (grumpy[i] ? window : base) += customers[i];        
            if (i >= X && grumpy[i - X])
                window -= customers[i - X];
            best_window = max(best_window, window);
        }
        return base + best_window;
    }
};


// @lc code=end

