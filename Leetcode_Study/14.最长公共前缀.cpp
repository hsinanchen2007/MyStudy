/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

/*

https://leetcode.cn/problems/longest-common-prefix/

14. 最长公共前缀

简单
2.6K
company
亚马逊
company
谷歌 Google
company
Facebook
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。 

提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

*/

// @lc code=start
class Solution100 {
public:
    // 2023.1.31, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-common-prefix.cpp
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); ++i) {
            for (const auto& str : strs) {
                if (i >= str.length() || str[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};


class Solution99 {
public:
    // 作者：CodeEXE
    // 链接：https://leetcode.cn/leetbook/read/array-and-string/ceda1/?discussion=rYF0cG
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string longestCommonPrefix(vector<string>& strs) {
        string out;
        if (strs.empty()) return out;
        // 最小长度，与strs[0]比较j
        for (int j = 0; j < strs[0].length(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (j > strs[i].length()-1 || strs[i][j] != strs[0][j]) {
                    return out;
                }
            }
            out.append(1, strs[0][j]);
        }
        return out;
    }
};


class Solution98 {
public:
    // 2023.1.31, from https://walkccc.me/LeetCode/problems/0014/
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        return "";

        for (int i = 0; i < strs[0].length(); ++i)
            for (int j = 1; j < strs.size(); ++j)
                if (i == strs[j].length() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);

        return strs[0];
    }
};


class Solution {
public:
    // 作者：fgsdfgsda
    // 链接：https://leetcode.cn/leetbook/read/array-and-string/ceda1/?discussion=QmU5mZ
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string longestCommonPrefix(vector<string>& strs) 
    {
        string same;
        same = strs[0];
        for(int i = 1; i < strs.size(); i++)
            for(int j = 0; j < same.size(); j++)
                if(same[j] != strs[i][j])
                    same.erase(j);
        return same;
    }
};


// @lc code=end

