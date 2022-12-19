### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    /*
        @param m 单字符数组，下标为i的字符在字符串中的位置。
        @param res 无重复字符的最长子串的长度
        @param left 子串滑动窗口左下标
        时间复杂度：O(n)
    */
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            // 当角标为i的字符是第一次出现，或者该字符在滑动窗口中未曾出现过。
            if (m[s[i]] == 0 || m[s[i]] < left) {
                // 计算窗口长度i-left+1，保存当前窗口长度和原窗口长度的最大值
                res = max(res, i-left+1);
            } 
            // 下标为i的字符在滑动窗口中有重复出现
            else {
                // 调整窗口左边界到下标为i的字符的最近位置
                left = m[s[i]];
            }
            // 更新下标为i的字符在字符串中的位置
            m[s[i]] = i+1;
        }
        return res;
    }
};


#include <iostream>
#include <string>
#include <stack>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int m[256] = {0}, res = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] == 0 || m[s[i]] < left) {
            res = max(res, i-left+1);
        } 
        else {
            left = m[s[i]];
        }
        m[s[i]] = i+1;
    }
    return res;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
}


```