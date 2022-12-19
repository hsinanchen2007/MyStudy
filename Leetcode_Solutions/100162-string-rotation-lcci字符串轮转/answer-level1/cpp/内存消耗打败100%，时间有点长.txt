
思路：
如果是旋转的，必定内容都相同，所有用了下排序sort



class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1!=s2)
            return false;
        return true;
    }
};