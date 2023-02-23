/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

/*

https://leetcode.cn/problems/valid-palindrome/

125. 验证回文串
简单
614
company
Facebook
company
谷歌 Google

如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。

示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。

示例 3：

输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。 

提示：

1 <= s.length <= 2 * 105
s 仅由可打印的 ASCII 字符组成

*/

// @lc code=start
class Solution100 {
    bool check(char c)
    {
        return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

public:
    // 2023.2.22, from https://www.acwing.com/solution/content/216/
    /*
        算法
        (线性扫描) O(n)

        用两个指针分别从前后开始，往中间扫描。
        每次迭代两个指针分别向中间靠近一步，靠近的过程中忽略除了字母和数字的其他字符。
        然后判断两个指针所指的字符是否相等，如果不相等，说明不是回文串。
        当两个指针相遇时，说明原字符串是回文串。

        时间复杂度分析：每个字符仅会被扫描一次，所以时间复杂度是 O(n)。    
    */
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j)
        {
            while (i < j && !check(s[i])) i ++ ;
            while (i < j && !check(s[j])) j -- ;
            if (s[i] != s[j] && s[i] != (s[j]^32)) return false;
            i ++, j --;
        }
        return true;
    }
};


class Solution99 {
public:
    // 2023.2.22, from https://walkccc.me/LeetCode/problems/0125/
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l]))
                ++l;
            while (l < r && !isalnum(s[r]))
                --r;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }

        return true;
    }
};


class Solution98 {
public:
    // 2023.2.22, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-palindrome.cpp
    // Time:  O(n)
    // Space: O(1)
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i, --j;
            }
        }
        return true;
    }
};


class Solution97 {
public:
    // 2023.2.22, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-palindrome.cpp
    // Time:  O(n)
    // Space: O(1)
    // Iterator solution.
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = prev(s.end());
        while (left < right) { 
            if (!isalnum(*left)) {
                ++left;
            } else if (!isalnum(*right)) {
                --right; 
            } else if (tolower(*left) != tolower(*right)) {
                return false;
            } else {
                ++left, --right;
            }
        }
        return true;
    }
};


class Solution96 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/125
    /*
        验证回文字符串是比较常见的问题，所谓回文，就是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
        但是这里，加入了空格和非字母数字的字符，增加了些难度，但其实原理还是很简单：只需要建立两个指针，left和right, 分别
        从字符的开头和结尾处开始遍历整个字符串，如果遇到非字母数字的字符就跳过，继续往下找，直到找到下一个字母数字或者结束
        遍历，如果遇到大写字母，就将其转为小写。等左右指针都找到字母数字时，比较这两个字符，若相等，则继续比较下面两个分别
        找到的字母数字，若不相等，直接返回false. 

        时间复杂度为O(n), 代码如下：    
    */
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isAlphaNum(s[left])) ++left;
            else if (!isAlphaNum(s[right])) --right;
            else if ((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left; --right;
            }
        }
        return true;
    }
    bool isAlphaNum(char &ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};


class Solution95 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/125
    /*
        我们也可以用系统自带的判断是否是数母字符的判断函数isalnum，参见代码如下；
        解法二：    
    */
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isAlphaNum(s[left])) ++left;
            else if (!isAlphaNum(s[right])) --right;
            else if ((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left; --right;
            }
        }
        return true;
    }
    bool isAlphaNum(char &ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};


class Solution94 {
public:
    // OJ: https://leetcode.com/problems/valid-palindrome/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    bool isPalindrome(string s) {
        int i = 0, j = s.size();
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};


class Solution93 {
public:
    // 2023.2.22, from https://zxi.mytechroad.com/blog/?s=LeetCode+125.
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (tolower(s[i++]) != tolower(s[j--])) 
                return false;
        }
        return true;
    }
};


class Solution92 {
public:
    // 2023.2.22, from https://github.com/azl397985856/leetcode/blob/master/problems/125.valid-palindrome.md
    /*
        思路
        这是一道考察回文的题目，而且是最简单的形式，即判断一个字符串是否是回文。

        针对这个问题，我们可以使用头尾双指针，

        如果两个指针的元素不相同，则直接返回 false,
        如果两个指针的元素相同，我们同时更新头尾指针，循环。 直到头尾指针相遇。
        时间复杂度为 O(n).

        拿“noon”这样一个回文串来说，我们的判断过程是这样的：

        125.valid-palindrome-1

        拿“abaa”这样一个不是回文的字符串来说，我们的判断过程是这样的：

        125.valid-palindrome-2

        关键点解析
        双指针    
    */
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        const char* s1 = s.c_str();
        const char* e = s1 + s.length() - 1;
        while (e > s1) {
            if (!isalnum(*s1)) {++s1; continue;}
            if (!isalnum(*e)) {--e; continue;}
            if (tolower(*s1) != tolower(*e)) return false;
            else {--e; ++s1;}
        }
        return true;
    }
};


class Solution {
public:
    // 2023.2.22, from https://ke.algomooc.com/p/t_pc/course_pc_detail/video/v_62c4267be4b0eca59c124739?product_id=p_62c2fa48e4b00a4f37220114&content_app_id=&type=8&parent_pro_id=p_6243bcc1e4b04e8d90291891
    bool isPalindrome(string s) {
        // 设置左右两个指针
        int left = 0 ;
        
        int right = s.size() - 1 ;


        // 移动和观察者两个指针所指向元素之间的关系
        while (left < right) {
            
            // 这里的逻辑有点像快速排序的代码

            // 如果 left 指向的元素不是字母、也不是数字
            // 那么可以忽略掉这个元素，即让 left 向右移动
            while (left < right && !isalnum(s[left])) {
                // left 向右移动
                left++;

            }

            // 如果 right 指向的元素不是字母、也不是数字
            // 那么可以忽略掉这个元素，即让 right 向左移动
            while (left < right && !isalnum(s[right])) {
                // right 向左移动
                right--;

            }

            // 来到这里时
            // 要么 left 和 right 相遇了，跳出循环
            // 要么 left 和 right 还没有相遇，并且它们都是指向字母或者数字
            if (left < right) {

                // 只需要判断一下 left 和 right 指向的元素值是否相同就行
                // 题目说明 可以忽略字母的大小写
                if (tolower(s[left]) != tolower(s[right])) {
                    // 不相同就直接说明不是回文串
                    return false;
                }

                // 否则，继续让两个指针向内移动

                // left 向右移动
                left++;

                // right 向左移动
                right--;
            }
        }

        // 最后，没有得到 false 的答案就说明是回文串，返回 true
        return true;

    }
};


// @lc code=end

