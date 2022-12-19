/*
遇到空格就加%20
记录一下处理的字符串的长度
*/
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
        int i=0;
        for(auto x:S)
        {
            i++;
            if(x==' ') res+="%20";
            else res+=x;
            if(i==length) break;
        }
        return res;
    }
};