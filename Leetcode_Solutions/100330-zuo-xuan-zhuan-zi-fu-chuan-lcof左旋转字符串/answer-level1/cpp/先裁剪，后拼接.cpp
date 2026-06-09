class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1=s;
        string s2=s;
        int len=s.size();
        s1=s1.substr(0,n);
        s2=s2.substr(n,len-n);
        return s2+s1;
    }
};