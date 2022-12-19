基本思想：
t为当前串，lec记录当前串左括号个数，ric记录当前串右括号个数
结束条件为 lec=n，此时补充右括号，压入结果vector
未结束则尝试向t压入左括号和右括号，再递归调用，调用完务必恢复！
时间复杂度O(n),每个左括号压入删除各一次；
```
class Solution {
public:
    void digui(string & t,int lec,int ric,int n,vector<string>& res)
    {
        if(lec==n)
        {
            res.push_back(t+string(n-ric,')'));
            return;
        }
        t.push_back('(');
        digui(t,lec+1,ric,n,res);
        t.erase(lec+ric,1);
        if(ric<lec)
        {
            t.push_back(')');
            digui(t,lec,ric+1,n,res);
            t.erase(lec+ric,1);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string t;
        digui(t,0,0,n,res);
        return res;
    }
};
```
