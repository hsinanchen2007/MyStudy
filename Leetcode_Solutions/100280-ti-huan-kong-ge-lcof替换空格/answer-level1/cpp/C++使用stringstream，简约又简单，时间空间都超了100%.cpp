class Solution {
public:
    string replaceSpace(string s) {
            stringstream ss;
            for(const auto& i:s)
            {
                if(i!=' '){
                    ss<<i;
                }else {
                    ss<<"%20";
                }
            }
            return ss.str();
    }
};