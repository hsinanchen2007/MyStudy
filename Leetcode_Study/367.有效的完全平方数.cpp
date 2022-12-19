/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

/*

https://leetcode.cn/problems/valid-perfect-square/

367. 有效的完全平方数
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。
 

示例 1：

输入：num = 16
输出：true

示例 2：

输入：num = 14
输出：false
 

提示：

1 <= num <= 2^31 - 1
通过次数162,651提交次数362,577

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, by Hsinan. Very similar to LC 69, we are looking for a middle value
    // by binary search as question required a O(logn)
    bool isPerfectSquare(int num) {
        // sanity check
        if (num < 2) return num;

        // define left and right pointers
        int left = 0;
        int right = num;

        // binary search with template code
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int sqrt = num / middle;

            if (middle > sqrt) {
                right = middle - 1;
            } else if (middle < sqrt) {
                left = middle + 1;
            } else {
                // middle is sams as sqrt, this means sqrt * middle = num
                // middle or sqrt value as integer may cause it shifted
                // Say middle = 5 / 2 = 2, while num is 5
                // then sqrt = 5 / 2 = 2, that makes middle and sqrt are same
                // the check below will further check its accuracy
                if (middle * middle == num) {
                    return true;
                } else {
                    left = middle + 1;
                }
            }
        }

        return false;
    }
};


class Solution99 {
public:
    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-perfect-square.cpp
    // Time:  O(logn)
    // Space: O(1)
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (mid >= num / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left == num / left && num % left == 0;
    }
};


class Solution98 {
public:
    // 2022.6.19, from AcWing https://www.acwing.com/video/1753/
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left < right) {
            // tricky below that "+1", in case of overflow, it uses "1ll" long long
            int middle = left + 1ll + right >> 1;
            if (middle <= num / middle) left = middle;
            else right = middle - 1;
        }
        // Actually (left * left == num) can also work
        return (right * right == num);
    }
};


class Solution97 {
public:
    // 2022.6.19, from https://ke.algomooc.com/detail/v_6281aa77e4b09dda1268b09c/3?from=p_6281a4bbe4b01a4851ff5f23&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 有效的完全平方数（ LeetCode 367 ）:https://leetcode-cn.com/problems/valid-perfect-square
    bool isPerfectSquare(int num) {
        // left 为当前区间最左侧的元素，可以获取到
        int left = 0;

        // right 为当前区间最右侧的元素，可以获取到
        int right = num;

        // 在区间 [left , right] 这个左闭右闭的区间里面去查找
        // 查找什么呢？
        // 查找是否存在一个数 a，使得 a * a = num

        // 在 while 循环里面，left 不断的向右移动，而 right 不断的向左移动
        // 当 [ left , right ] 这个区间不存在元素的时候，才跳出 while 循环，也就是当 left > right 时跳出循环
        // 即当 left = right + 1 时，搜索区间没有元素了
        // 由于 left 和 right 相遇的时候指向同一个元素，这个元素是存在于 [ left , right] 区间，这个区间就一个元素
        // 所以此时 while 循环的判断可以使用等号
        while (left <= right) {
            
            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 判断中间元素的平方与 num 的大小
            // 如果 mid * mid < num
            
            // mid * mid 的数值有可能超过 int 类型的最大数
            // 使用 long 
            long square = (long) mid * mid;
            
            // 中间元素的平方小于了目标值 num
            // 数组为 [ 0 , n ]
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ left , mid ] 这个区间中的所有元素的平方都小于目标值 num
            // 因此，缩小查找区间为 [ mid + 1 , right]
            if (square < num){
                // 也就是说缩小之后的区间最左侧位置为 mid + 1
                left = mid + 1;
            
            // 中间元素的平方大于了目标值 num
            // 数组为 [ 0 , n ]
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ mid , right ] 这个区间中的所有元素的平方都大于目标值 num
            // 因此，缩小查找区间为 [ left , mid - 1]
            }else if( square > num){
                // 也就是说缩小之后的区间最右侧位置为 mid - 1
                right = mid - 1 ;
            
            // 中间元素的平方等于了目标值 num
            }else if( square == num){
                // 直接返回结果即可
                return true;
            }
        }

        // 查找完区间中的所有元素都没有找到，返回 false
        return false;
    }
};


class Solution96 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/367.%20Valid%20Perfect%20Square
    // OJ: https://leetcode.com/problems/valid-perfect-square/
    // Author: github.com/lzl124631x
    // Time: O(sqrt(num))
    // Space: O(1)
    bool isPerfectSquare(int num) {
        long i = 0;
        while (i * i < num) ++i;
        return i * i == num;
    }
};


class Solution95 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/367.%20Valid%20Perfect%20Square
    // OJ: https://leetcode.com/problems/valid-perfect-square/
    // Author: github.com/lzl124631x
    // Time: O(log(num))
    // Space: O(1)
    bool isPerfectSquare(int num) {
        long L = 1, R = num;
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (M * M == num) return true;
            if (num / M < M) R = M - 1;
            else L = M + 1;
        }
        return false;
    }
};


class Solution94 {
public:
    // 2022.7.27, from https://walkccc.me/LeetCode/problems/0367/
    // Time: O(lognum)
    // Space: O(1)
    bool isPerfectSquare(int num) {
        long l = 1;
        long r = num;

        while (l < r) {
            const long m = (l + r) / 2;
            if (m >= num / m)
                r = m;
            else
                l = m + 1;
        }

        return l * l == num;
    }
};


class Solution93 {
public:
    // 2022.7.27, from https://github.com/MaskRay/LeetCode/blob/master/valid-perfect-square.cc
    // Valid Perfect Square
    // Hacker's Delight (2nd) 11.1.1
    // 46340 = floor(sqrt(INT_MAX))
    bool isPerfectSquare(int num) {
        int x = 46340, y;
        while ((y = (x+num/x)>>1) < x)
        x = y;
        return x*x == num;
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/367
    // Note, its solution 1 cannot work!!
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
}; 


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/367
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/367
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};


class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

