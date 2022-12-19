/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

/*

https://leetcode.cn/problems/reverse-string/

344. 反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。


示例 1：

输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：

输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
 

提示：

1 <= s.length <= 105
s[i] 都是 ASCII 码表中的可打印字符
通过次数579,167提交次数734,078

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.23, by Hsinan
    void reverseString(vector<char>& s) {
        // get size and sanity check
        int size = s.size();
        if (size <= 1) {
            return;
        }
        
        // use two pointers, from beginning and end
        int i = 0, j = size - 1;

        // reverse
        while (i <= j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++, j--;
        }
        return;
    }
};


class Solution99 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    /*
        先说一说题外话：

        对于这道题目一些同学直接用C++里的一个库函数 reverse，调一下直接完事了， 相信每一门编程语言都有这样的库函数。
        如果这么做题的话，这样大家不会清楚反转字符串的实现原理了。

        但是也不是说库函数就不能用，是要分场景的。
        如果在现场面试中，我们什么时候使用库函数，什么时候不要用库函数呢？

        如果题目关键的部分直接用库函数就可以解决，建议不要使用库函数。
        毕竟面试官一定不是考察你对库函数的熟悉程度， 如果使用python和java 的同学更需要注意这一点，因为python、
        java提供的库函数十分丰富。如果库函数仅仅是 解题过程中的一小部分，并且你已经很清楚这个库函数的内部实现原理的话，
        可以考虑使用库函数。建议大家平时在leetcode上练习算法的时候本着这样的原则去练习，这样才有助于我们对算法的理解。
        不要沉迷于使用库函数一行代码解决题目之类的技巧，不是说这些技巧不好，而是说这些技巧可以用来娱乐一下。
        真正自己写的时候，要保证理解可以实现是相应的功能。

        接下来再来讲一下如何解决反转字符串的问题。

        大家应该还记得，我们已经讲过了206.反转链表。
        在反转链表中，使用了双指针的方法。

        那么反转字符串依然是使用双指针的方法，只不过对于字符串的反转，其实要比链表简单一些。
        因为字符串也是一种数组，所以元素在内存中是连续分布，这就决定了反转链表和反转字符串方式上还是有所差异的。
        如果对数组和链表原理不清楚的同学，可以看这两篇，关于链表，你该了解这些！，必须掌握的数组理论知识。
        对于字符串，我们定义两个指针（也可以说是索引下标），一个从字符串前面，一个从字符串后面，两个指针同时向中间移动，
        并交换元素。

        以字符串hello为例，过程如下：

        344.反转字符串

        不难写出如下C++代码:

        void reverseString(vector<char>& s) {
            for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
                swap(s[i],s[j]);
            }
        }
        循环里只要做交换s[i] 和s[j]操作就可以了，那么我这里使用了swap 这个库函数。大家可以使用。
        因为相信大家都知道交换函数如何实现，而且这个库函数仅仅是解题中的一部分， 所以这里使用库函数也是可以的。
        swap可以有两种实现。

        一种就是常见的交换数值：

        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        一种就是通过位运算：

        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];

        这道题目还是比较简单的，但是我正好可以通过这道题目说一说在刷题的时候，使用库函数的原则。
        如果题目关键的部分直接用库函数就可以解决，建议不要使用库函数。

        如果库函数仅仅是 解题过程中的一小部分，并且你已经很清楚这个库函数的内部实现原理的话，可以考虑使用库函数。
        本着这样的原则，我没有使用reverse库函数，而使用swap库函数。

        在字符串相关的题目中，库函数对大家的诱惑力是非常大的，因为会有各种反转，切割取词之类的操作，这也是为什么
        字符串的库函数这么丰富的原因。相信大家本着我所讲述的原则来做字符串相关的题目，在选择库函数的角度上会有所
        原则，也会有所收获。

        C++代码如下：
    */
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }
};


class Solution98 {
public:
    // 2022.7.23, https://github.com/lzl124631x/LeetCode/tree/master/leetcode/344.%20Reverse%20String
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-string.cpp
    // Time:  O(n)
    // Space: O(1)
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};


class Solution96 {
public:
    // 2022.7.23, from AcWing
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
            swap(s[i], s[j]);
    }
};


class Solution95 {
public:
    // 2022.7.27, from https://walkccc.me/LeetCode/problems/0344/
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        swap(s[l++], s[r--]);
    }
};


class Solution94 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/344
    /*
        这道题没什么难度，直接从两头往中间走，同时交换两边的字符即可，参见代码如下：

        解法一：
    */
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/344
    /*
        我们也可以用 swap 函数来帮助我们翻转：

        解法二：
    */
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

