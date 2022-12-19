class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res,"",n,0,0);
        return res;
    }

    void dfs(vector<string>& res,string str,int n, int l , int r)
    {
        if(l>n || r>n|| r > l)
        {
            return ;
        }

        if(l == r && r == n)
        {
            res.push_back(str);
        }

        dfs(res,str+"(",n,l+1,r);
        dfs(res,str+")",n,l,r+1);

    }

};

判断回溯很简单，拿到一个问题，你感觉如果不穷举一下就没法知道答案，那就可以开始回溯了。

一般回溯的问题有三种：

Find a path to success 有没有解
Find all paths to success 求所有解
求所有解的个数
求所有解的具体信息
Find the best path to success 求最优解

找到结束的条件

作者：fuxuemingzhu
链接：https://leetcode-cn.com/problems/generate-parentheses/solution/ru-men-ji-bie-de-hui-su-fa-xue-hui-tao-lu-miao-don/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。