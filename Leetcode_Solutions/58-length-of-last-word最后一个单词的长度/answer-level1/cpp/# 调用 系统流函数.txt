
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream cs(s);
        string result;
        while(cs>>result){}
        return result.size();
    }
};
