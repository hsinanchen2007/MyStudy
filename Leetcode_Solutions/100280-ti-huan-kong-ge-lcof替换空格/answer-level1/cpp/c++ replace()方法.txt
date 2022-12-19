class Solution {
public:
    string replaceSpace(string s) {
        if (s.size()==0) return s;
        string s1=" ";
        string s2="%20";
        string::size_type pos=s.find(s1);
        while(pos != string::npos){
            s.replace(pos, s1.size(), s2);
            pos=s.find(s1);
        }
        return s;
    }
};