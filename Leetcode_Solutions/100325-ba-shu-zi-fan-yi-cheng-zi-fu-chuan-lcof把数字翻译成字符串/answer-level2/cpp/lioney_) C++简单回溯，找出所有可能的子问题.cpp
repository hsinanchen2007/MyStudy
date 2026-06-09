```
class Solution {
public:
    int translateNum(int num) {
        int res = 0;
        helper(to_string(num), 0, res);
        return res;
    }
private:
    void helper(string s, int index, int& res)
    {
        if(index>=s.size()) {
            res++; 
            return;
        }
        helper(s, index+1, res);
        string t=s.substr(index,2);
        if(index+1<s.size() && t<"26" && t[0]!='0')
            helper(s, index+2, res);
    }
};
```
