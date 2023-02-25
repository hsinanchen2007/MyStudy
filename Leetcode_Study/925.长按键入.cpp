/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

/*

https://leetcode.cn/problems/long-pressed-name/

925. 长按键入
简单
259
company
彭博 Bloomberg

你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。 

提示：

1 <= name.length, typed.length <= 1000
name 和 typed 的字符都是小写字母

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.24, from https://www.acwing.com/activity/content/code/content/1337043/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/1337043/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] != typed[j]) return false;
            int x = i + 1, y = j + 1;
            while (x < name.size() && name[x] == name[i]) x ++ ;
            while (y < typed.size() && typed[y] == typed[j]) y ++ ;
            if (x - i > y - j) return false;
            i = x, j = y;
        }
        return i == name.size() && j == typed.size();
    }
};


class Solution99 {
public:
    // 2023.2.24, from https://walkccc.me/LeetCode/problems/0925/
    bool isLongPressedName(string name, string typed) {
        int i = 0;

        for (int j = 0; j < typed.length(); ++j)
        if (i < name.length() && name[i] == typed[j])
            ++i;
        else if (j == 0 || typed[j] != typed[j - 1])
            return false;

        return i == name.length();
    }
};


class Solution98 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/925
    /*
        这道题说是你朋友在用键盘敲入名字的时候，对于某个字母可能会长时间按键，这导可能会有多个相同字母输入，这种情况是允许的，
        现在给了两个字符串，name 是朋友的名字，typed 是朋友敲入的字符串，问 typed 是否是朋友敲入的名字。其实这道题的本质是，
        对于 name 中每个位置的字母，对应在 typed 中的出现次数一定要相等或者更多，但是直接统计每个字符出现的次数是不对的，因为
        位置关系很重要，比如 abb 和 abab，虽然后者中a和b的出现次数都大于等于前者，但还是要返回 false。博主最先想的方法是用
        两个指针i和j分别提取 name 和 typed 字符串中每个字母出现的次数，如果 typed 中的次数小于 name 中的次数，则直接返回 
        false 即可，最终循环结束后，i和j应该分别为 name 和 typed 的长度，此时返回 true，否则返回 false，参见代码如下：

        解法一：    
    */
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, m = name.size(), n = typed.size();
        while (i < m || j < n) {
            if (name[i] != typed[j]) return false;
            int start1 = i, start2 = j;
            while (i < m - 1 && name[i] == name[i + 1]) ++i;
            while (j < n - 1 && typed[j] == typed[j + 1]) ++j;
            if (j - start2 + 1 < i - start1 + 1) return false;
            ++i; ++j;
        }
        return i == m && j == n;
    }
};


class Solution97 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/925
    /*
        可以写的简洁一些，不需要使用那么多的 while 循环，而是直接用j遍历 typed 中每个字母，i初识时指向 name 的第一个字母，
        假如i小于m，且 name[i] 等于 typed[j-1] 时，则i自增1，否则的话，若此时j为0（说明第一个字母就不匹配），或者 typed[j] 
        不等于 typed[j - 1]（说明出现了无法匹配的新字母），则直接返回 false。循环退出后若i等于m则返回 true，否则返回 false，
        参见代码如下：

        解法二：    
    */
    bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.size(), n = typed.size();
        for (int j = 0; j < n; ++j) {
            if (i < m && name[i] == typed[j]) ++i;
            else if (!j || typed[j] != typed[j - 1]) return false;
        }
        return i == m;
    }
};


class Solution96 {
public:
    // https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rwnhos/
    // 作者：郫县林俊杰
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rwnhos/?discussion=kM4tdr
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.size()&&j<typed.size()){
            if(name[i]!=typed[j]) return false;
            auto x=i+1,y=j+1;
            while(x<name.size()&&name[i]==name[x]) x++;
            while(y<typed.size()&&typed[j]==typed[y]) y++;
            if(x-i>y-j) return false;
            i=x,j=y;
        }
        return i==name.size()&&j==typed.size();
    }
};


class Solution95 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/long-pressed-name.cpp
    // Time:  O(n)
    // Space: O(1)
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        for (int j = 0; j < typed.length(); ++j) {
            if (i < name.length() && name[i] == typed[j]) {
                ++i;
            } else if (j == 0 || typed[j] != typed[j - 1]) {
                return false;
            }
        }
        return i == name.length();
    }
};


class Solution94 {
public:
    // OJ: https://leetcode.com/problems/long-pressed-name/
    // Author: github.com/lzl124631x
    // Time: O(M + N)
    // Space: O(1)
    bool isLongPressedName(string name, string typed) {
        int i = 0, M = name.size(), j = 0, N = typed.size();
        while (i < M && j < N) {
            char c = name[i];
            int a = 0, b = 0;
            while (i < M && name[i] == c) ++i, ++a;
            while (j < N && typed[j] == c) ++j, ++b;
            if (a > b) return false;
        }
        return i == M && j == N;
    }
};


class Solution {
public:
    // 2023.2.24, from https://zxi.mytechroad.com/blog/?s=LeetCode+925.
    // Author: Huahua, 0 ms
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size()) {      
        if (name[i] == typed[j]) {
            ++i;
            ++j;
        } else if (j > 0 && typed[j] == typed[j - 1]) {
            ++j;
        } else {
            return false;
        }
        }
        while (j < typed.size() && typed[j] == typed[j - 1]) ++j;
        return i == name.size() && j == typed.size();
    }
};


// @lc code=end

