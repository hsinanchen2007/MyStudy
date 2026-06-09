### 解题思路
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 


### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.size()<2) return s;
        string res = s;
        int l(0),r(0);
        for(int i = 0; i<s.size();i++){
            if(s[i]!=' ') r++;
            else{
                reverse(res.begin()+l,res.begin()+r);
                l = r+1;
                r = l;
            }
        }
        if(l<r)  reverse(res.begin()+l,res.begin()+r);
        return res;
    }
};
```