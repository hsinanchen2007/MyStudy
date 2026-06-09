class Solution {
public:
    int lengthOfLastWord(string s) {
        getline(cin,s);
        size_t pos=s.rfind(' ');
        return s.size()-pos-1;
    }
};