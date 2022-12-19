### 解题思路


 一看是最长子串问题, 就想到了动态规划, 然后开始按照题目的意思开始定义子问题, f[0..i], 从 0 到 i 的最长子串是什么? 
 想到这里, 发现该 递归表达式不好写出来, 所以就想到另一种方法, 定义g[0...i]为以i结尾的无重复字符的最长子串是啥,
  然后 f[0...i] 就是 max {g(0), ..., g(i)}. 所以现在的目的就变成了求 以 i 结尾的最长无重复字符子串了. 这个该怎么求呢?
  就是解题的代码所表示的那样了. 

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int valid_zone = 0;
        // 26 个字母
        int maxlen = 0;
        std::unordered_map<char, int> latest_pos;
        int tmplength;
        for(int i=0; i<s.size(); i++) {
            if(latest_pos.find(s[i]) != latest_pos.end() && valid_zone<=latest_pos[s[i]]) {
                valid_zone = latest_pos[s[i]] + 1;
                latest_pos[s[i]] = i;
            }else {
                tmplength = i-valid_zone+1;
                maxlen = maxlen > tmplength ? maxlen : tmplength;
                latest_pos[s[i]] = i;
            }
        }
        return maxlen;
    }
};

```