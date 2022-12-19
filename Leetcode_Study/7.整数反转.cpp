/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

/*

https://leetcode.cn/problems/reverse-integer/

7. 整数反转
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321

示例 2：

输入：x = -123
输出：-321

示例 3：

输入：x = 120
输出：21

示例 4：

输入：x = 0
输出：0
 

提示：

-231 <= x <= 231 - 1
通过次数1,027,693提交次数2,911,171

*/

// @lc code=start
class Solution100 {
public:
    // 2022.5.30, from LG solution
    //   1. Do integer limit check first, and return 0 if they are over limit
    //   2. Check and convert number to positive first, sign is used to
    //      determine positive or negative number by 1 or -1
    //   3. do (last = x % 10) in while condition
    //   4. Remember if (last != 0), we need to apply it back, also
    //      convert it to long and do integer limit check
    //   5. At the end of return, apply sign back
    int reverse(int x) {
        // sanity check, INT_MAX is 2147483648, INT_MIN is -2147483648
        // if the given number is reversed, it will cause over integer limit
        if (x == INT_MAX || x == INT_MIN) return 0;

        // check the given x is positive or negative number, and always
        // convert it to positive number first
        // note that the sign should be 1 or -1, not 1 or 0, as we will 
        // need to (result * sign) at the end, so if sign is 0, that will 
        // cause negative number returns 0
        int sign = (x > 0) ? 1 : -1;
        x = (x < 0) ? -x : x;

        // defnie result and last, note that these two variables needed to 
        // be used inside while loop and outside later
        int result = 0;
        int last = 0;

        // key point condition, assign (x % 10) first, then compare with x
        // itself, if they are same, this is last number, otherwise run into
        // this while loop, for example 123, we want to reverse it to 321
        while ((last = x % 10) != x) {
            result = (result * 10) + last;
            x = x / 10;
        }

        // if last is not 0, if won't run into while loop
        // that means above will only include (n-1) numbers
        // from original n numbers, for example, 123, and 
        // after while loop, we only get 32, where 1 was not 
        // executed in while loop, so we need below code
        // if last = 0, for example, original 320 will become
        // 23, not 023, so we can skip the last if it is 0
        if (last != 0) {
            // note here we do a small to large conversion, from integer to long
            // so it won't have over integer limit issue
            long re = result;
            re = re * 10 + last;

            // do the limit check again before return
            if (re > INT_MAX || re < INT_MIN) {
                return 0;
            } else {
                // convert it back to integer from long
                result = (int)re;
            }
        }

        return result * sign;
    }
};


class Solution99 {
public:
    // 2022.5.31, from Leetcode 題目詳解, lvyilong316@163.com
    // However, need to add the INT_MAX/INT_MIN check as Leetcode
    // now will check the integer overflow in the submission cases
    int reverse(int x) {
        // need to define "result" as long, not int, to detect and prevent integer overflow
        long result = 0;
        for (; x; x/=10) {
            // tricky part, result starts with 0, so (x % 10) returns the 
            // last digit, then move to next one
            result = (result * 10) + (x % 10);
        
            // need this check to avoid integer overflow
            if (result >= INT_MAX || result <= INT_MIN) return 0;
        }
        return (int)result;
    }
};


class Solution98 {
public:
    // 2022.6.4, from AcWing https://www.acwing.com/video/1323/
    // it can use integer without converting anything to long long
    // two conditions that over limit:
    //   1. r * 10 + x % 10 > INT_MAX
    //      ==> r > (INT_MAX - x % 10) / 10
    //   2. r * 10 + x % 10 < INT_MIN
    //      ==> r < (INT_MIN - x % 10) / 10
    int reverse(int x) {
        int r = 0;
        while (x) {
            if (r > 0 && r > (INT_MAX - x % 10) / 10) return 0;
            if (r < 0 && r < (INT_MIN - x % 10) / 10) return 0;
            r = r * 10 + x % 10;
            x = x / 10;
        }
        return r;
    }
};


class Solution97 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-integer.cpp
    // Time:  O(logn) = O(1)
    // Space: O(1)
    int reverse(int x) {
        int result = 0;
        while (x) {
            if (result > numeric_limits<int>::max() / 10 ||
                (result == numeric_limits<int>::max() / 10 && x % 10 > numeric_limits<int>::max() % 10)) {
                return 0;
            }
            if (result < numeric_limits<int>::min() / 10 ||
                (result == numeric_limits<int>::min() / 10 && x % 10 < numeric_limits<int>::min() % 10)) {
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://ke.algomooc.com/detail/v_62c8dde1e4b0a51feefd138e/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_62c8ddd7e4b0a51feefd138b
    int reverse(int x) {
        // 记录反转成功之后的结果
        int res = 0;

        // 对于需要反转的数字 x
        // 每一次都按照【从后向前】的顺序去访问每个元素
        // 在访问过程中会执行一些逻辑判断
        // 判断过程中可能会由于越界直接返回 0 
        // 否则会一直判断下去，直到 x 的每个元素均被访问，即 x = 0 时跳出循环
        while( x != 0 ) {

            // 每一次都先获取末尾数字
            int lastNum = x % 10;

            // 假设有 1147483649 这个数字，它是小于最大的 32 位整数 2147483647 的
            // 但是将这个数字反转过来后就变成了 9463847411 ，超过了最大的 32 位整数
            // 根据题目要求需要返回 0

            // 在获取到 lastNum 的过程中，需要判断一下当前的 res 是否合法
            // 如果不合法，就不用再添加 lastNum，结果直接返回 0 就行

            // 1、res 为正数并且大于了 214748364 ，即最小为 214748365 ，那么无论 lastNum 为多少，添加上去都会不合法
            // 比如 lastNum 最小为 0 ，形成了 2147483650 ，也是大于 2147483647
            // 2、res 等于了 214748364 ，那么在它的后面添加 8、9，就会形成 2147483648 、2147483649 这两个数
            // 而这两个数都不合法，返回 0
            if (res > 214748364 || ( res == 214748364 && (lastNum == 8 || lastNum == 9 ))) {
                // 返回 0
                return 0;

            }
            // 3、res 为负数并且小于了 -214748364 ，即最大为 214748365 ，那么无论 lastNum 为多少，添加上去都会不合法
            // 比如 lastNum 最小为 9 ，形成了 -2147483650 ，也是小于 -2147483648
            // 4、res 等于了 -214748364 ，那么在它的后面添加 9，就会形成 -2147483649 这个数
            // 而这个数不合法，返回 0
            if (res < -214748364 || (res == -214748364 && lastNum == -9 )) {
                // 返回 0
                return 0;

            }

            // 5、否则说明可以继续添加
            // res 全部元素向左移动，即 *10
            res = res * 10 + lastNum;

            // 6、在去获取 x 的下一个数
            x /= 10;

        }

        // 返回结果
        return res;

    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/7.%20Reverse%20Integer
    // OJ: https://leetcode.com/problems/reverse-integer/
    // Author: github.com/lzl124631x
    // Time: O(1)
    // Space: O(1)
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int r = 0, sign = x >= 0 ? 1 : -1, y = sign * x, p = 1;
        while (y) {
            y /= 10;
            if (y) p *= 10;
        }
        x = sign * x;
        while (x) {
            int d = x % 10;
            x /= 10;
            if ((INT_MAX - r) / p < d) return 0;
            r += p * d;
            p /= 10;
        }
        return sign * r;
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/7.%20Reverse%20Integer
    // OJ: https://leetcode.com/problems/reverse-integer/
    // Author: github.com/lzl124631x
    // Time: O(1)
    // Space: O(1)
    int reverse(int x) {
        int r = 0;
        while (x) {
            int d = x % 10;
            x /= 10;
            if ((r >= 0 && (r > INT_MAX / 10 || INT_MAX - 10 * r < d))
                || (r < 0 && (r < INT_MIN / 10 || INT_MIN - 10 * r > d))) return 0;
            r = r * 10 + d;
        }
        return r;
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0007/
    // Time: O(logx)
    // Space: O(1)
    int reverse(int x) {
        long ans = 0;

        while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
        }

        return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
    }
};


class Solution92 {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/7
    /*
        翻转数字问题需要注意的就是溢出问题，看了许多网上的解法，由于之前的 OJ 没有对溢出进行测试，
        所以网上很多人的解法没有处理溢出问题也能通过 OJ。现在 OJ 更新了溢出测试，所以还是要考虑到。
        为什么会存在溢出问题呢，由于int型的数值范围是 -2147483648～2147483647， 那么如果要翻转 
        1000000009 这个在范围内的数得到 9000000001，而翻转后的数就超过了范围。博主最开始的想法是，
        用 long 型数据，其数值范围为 -9223372036854775808~9223372036854775807， 远大于 
        int 型这样就不会出现溢出问题。但实际上 OJ 给出的官方解答并不需要使用 long，一看比自己的
        写的更精简一些，它没有特意处理正负号，仔细一想，果然正负号不影响计算，而且没有用 long 型数据，
        感觉写的更好一些，那么就贴出来吧：

        解法一：
    */
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/7
    /*
        在贴出答案的同时，OJ 还提了一个问题 To check for overflow/underflow, we could 
        check if ret > 214748364 or ret < –214748364 before multiplying by 10. 
        On the other hand, we do not need to check if ret == 214748364, why? 
        （214748364 即为 INT_MAX / 10）

        为什么不用 check 是否等于 214748364 呢，因为输入的x也是一个整型数，所以x的范围也应该在 
        -2147483648～2147483647 之间，那么x的第一位只能是1或者2，翻转之后 res 的最后一位只能
        是1或2，所以 res 只能是 2147483641 或 2147483642 都在 int 的范围内。但是它们对应的x为 
        1463847412 和 2463847412，后者超出了数值范围。所以当过程中 res 等于 214748364 时， 
        输入的x只能为 1463847412， 翻转后的结果为 2147483641，都在正确的范围内，所以不用 check。

        我们也可以用 long 型变量保存计算结果，最后返回的时候判断是否在 int 返回内，但其实题目中说
        了只能存整型的变量，所以这种方法就只能当个思路扩展了，参见代码如下：

        解法二：
    */
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

