/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

/*

https://leetcode.cn/problems/sqrtx/

69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

 
示例 1：

输入：x = 4
输出：2

示例 2：

输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 

提示：

0 <= x <= 231 - 1
通过次数557,697提交次数1,436,404

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, from CyC2018/CS-Notes
    int mySqrt(int x) {
        // sanity check
        if (x <= 1) return x;

        // define left and right pointers
        int left = 0, right = x;

        // find the sqrt
        while (left <= right) {
            int middle = left + (right - left) / 2;

            // key point is below. If sqrt * middle = x, that means
            // we found exactly sqrt. This is only extra one 
            // compared to template
            // For example x = 4, then we have left = 0, right = 4
            // and middle = 2, which is its sqrt 
            int sqrt = x/middle;

            if (sqrt == middle) {
                return middle;
            } else if (middle > sqrt) {
                right = middle -1;
            } else {
                left = middle + 1;
            }
        }

        // again, similar to LC 35, when we didn't find the answer in while loop,
        // at this point, right < left (right pointer becomes at left side of left pointer)
        // we should return right pointer here, since we will should the integer value of 
        // sqrt, for example, 8's sqrt is 2.82842, we pick integer "2" as answer,
        // which is right pointer at this moment
        return right;

        // After a try, we can also return (left - 1) like other answers below
        // return (left - 1);
    }
};


class Solution99 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-69-Sqrt-x-3.html?q=sqrt
    // Time Complexity: O(log n), Space Complexity: O(1)
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 0, right = x / 2 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Move left == right, then we need to move left back
            x / mid < mid ? right = mid : left = mid + 1;
        }

        return left - 1;
    }
};


class Solution98 {
public:
    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sqrtx.cpp
    // Time:  O(logn)
    // Space: O(1)
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int left = 1, right = x / 2;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left - 1;
    }
};


class Solution97 {
public:
    // 2022.6.19, from AcWing https://www.acwing.com/video/1407/
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left < right) {
            // tricky below to use "1ll" to avoid overflow 
            int middle = left + 1ll + right >> 1;
            if (middle <= x / middle) left = middle;
            else right = middle - 1;
        }

        return right;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(sqrt(N))
    // Space: O(1)
    int mySqrt(int x) {
        long i = 0;
        while (i * i <= x) ++i;
        return i - 1;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // L <= R template.
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int mySqrt(int x) {
        long L = 0, R = x;
        while (L <= R) {
            long M = (L + R) / 2;
            if (M * M <= x) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // use L < R template
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int mySqrt(int x) {
        long L = 0, R = x;
        while (L < R) {
            long M = (L + R + 1) / 2;
            if (M * M <= x) L = M;
            else R = M - 1;
        }
        return L;
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // Newton's method, Reference: https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) r = (r + x / r) / 2;
        return r;
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0069/
    // Time: O(logx)
    // Space: O(1)
    int mySqrt(int x) {
        unsigned l = 1;
        unsigned r = x + 1u;

        while (l < r) {
        const unsigned m = (l + r) / 2;
        if (m > x / m)
            r = m;
        else
            l = m + 1;
        }

        // l: smallest number s.t. l * l > x
        return l - 1;
    }
};


class Solution91 {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-69-Sqrt-x-3.html?h=mysqrt
    // Time Complexity: O(log n), Space Complexity: O(1)
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 0, right = x / 2 + 1;
        while (left < right) {
        int mid = left + (right - left) / 2;
        // Move left == right, then we need to move left back
        x / mid < mid ? right = mid : left = mid + 1;
        }

        return left - 1;
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/69
    /*
        这道题要求我们求平方根，我们能想到的方法就是算一个候选值的平方，然后和x比较大小，为了缩短查找时间，我们采用
        二分搜索法来找平方根，这里属于博主之前总结的 LeetCode Binary Search Summary 二分搜索法小结 中的第三类
        的变形，找最后一个不大于目标值的数，这里细心的童鞋可能会有疑问，在总结贴中第三类博主的 right 用的是开区间，
        那么这里为啥 right 初始化为x，而不是 x+1 呢？因为总结帖里的 left 和 right 都是数组下标，这里的 left 和 
        right 直接就是数字本身了，一个数字的平方根是不可能比起本身还大的，所以不用加1，还有就是这里若x是整型最大值，
        再加1就会溢出。最后就是返回值是 right-1，因为题目中说了要把小数部分减去，只有减1才能得到正确的值，
        代码如下：

        解法一：
    */
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};


class Solution89 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/69
    /*
        这道题还有另一种解法，是利用牛顿迭代法，记得高数中好像讲到过这个方法，是用逼近法求方程根的神器，在这里也可以借用一下，
        可参见网友 Annie Kim's Blog的博客，因为要求 x2 = n 的解，令 f(x)=x2-n，相当于求解 f(x)=0 的解，可以求出递推
        式如下：

        xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2

        解法二：
    */
    int mySqrt(int x) {
        if (x == 0) return 0;
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};


class Solution88 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/69
    /*
        也是牛顿迭代法，写法更加简洁一些，注意为了防止越界，声明为长整型，参见代码如下：

        解法三：
    */
    int mySqrt(int x) {
        long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution {
public:
    // 2022.9.3, from https://leetcode-solution.cn/book
    int mySqrt(int x) {
        long l = 0, h = x;
        while (l <= h) {
            long mid = l + (h - l) / 2;
            if (l == h || l + 1 == h) {
                break;
            } else if (mid * mid > x) {
                h = mid - 1;
            } else {
                l = mid;
            }
        }
        if (h * h <= x) {
            return (int)h;
        } else {
            return (int)l;
        }
    }
};


// @lc code=end

