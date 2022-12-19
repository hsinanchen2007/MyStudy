这道题的问题在如何判断s中的每一个元素去匹配t，如果s中的每一个元素都有t中的顺位的元素与之对应（即按顺序往后匹配），那么s中的每一个元素也就在t中找到了有顺序的匹配。
比如s = "abc"，t = "ajiodsjidobdjiosdjc";
按顺序在t中分别匹配到a,b,c

以下是代码
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        int i = 0,j = 0;
        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
                ++i;//若匹配上了，则移动s的指针
            ++j;//不管怎样都移动t的指针
        }
        return i == s.size();//倘若i=s的长度，则说明s中的每一个元素都有t中的带有顺序的匹配上了，即返回true，反之为false
    }
};