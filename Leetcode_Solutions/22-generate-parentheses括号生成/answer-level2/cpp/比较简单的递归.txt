```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,n,"",res);
        return res;
    }

    void helper(int x,int y,string str,vector<string>& res){
        if(x < 0 || y < 0) return;
        else if(!x && !y) res.push_back(str);
        helper(x - 1,y,str + "(",res);  //将左括号加到字符串中
        if(x < y)   helper(x,y - 1,str + ")",res);  //将右括号加到字符串中，但左括号在右括号左边
    }
};
```
