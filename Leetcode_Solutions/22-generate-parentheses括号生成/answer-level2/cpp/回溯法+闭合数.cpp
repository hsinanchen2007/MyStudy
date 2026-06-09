```
class Solution {
public:
    // 方法一 回溯法
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        vector<string> res;
        string tmp="";
        backtrack(res,tmp,n,n);
        return res;
    }
    void backtrack(vector<string>& res,string tmp,int left,int right){
        if(left==0&&right==0) res.emplace_back(tmp);
        if(left>0){
            tmp +="(";
            backtrack(res,tmp,left-1,right);
            tmp.pop_back();
        }
        if(right>0&&right>left){
            tmp +=")";
            backtrack(res,tmp,left,right-1);
            tmp.pop_back();
        }
    }
};
```
```
class Solution {
public:
    //方法二 闭合数
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)  res.emplace_back("");
        for(int i = 0; i < n; i++)
            for(string left: generateParenthesis(i))
                for(string right: generateParenthesis(n - 1 - i))
                    res.emplace_back("(" + left + ")" + right);
        return res;
    }
};
```

