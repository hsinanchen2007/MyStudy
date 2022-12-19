分享大神的代码，思路参考“回溯、优化（使用动态规划预处理数组）”一文，代码参考大神“华科平凡”。
链接：https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/
深度优先搜索（也可以称为回溯法）,DFS
因为需要输出所有的可行解，所以采用深度优先遍历（回溯法）。
输出最佳解的题目一般可以使用动态规划。
![298a80282ac3505fec3710abdc1e656c591cf7acaa3ba976151480729244b649-image.png](https://pic.leetcode-cn.com/823467291241f84018d13b378c1254d34405613ce2a34816eef57925b77f16ef-298a80282ac3505fec3710abdc1e656c591cf7acaa3ba976151480729244b649-image.png)

```
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s,cur,res);
        return res;
    }
 
    bool isPalindrome(string s){
        return s==string(s.rbegin(),s.rend());
    }
 
    void dfs(string s,vector<string> &cur,vector<vector<string>> &res){
        if (s==""){
            res.push_back(cur);
            return;
        }
 
        for (int i = 1; i <= s.length(); ++i) {
            string sub=s.substr(0,i);
            if (isPalindrome(sub)){
                cur.push_back(sub);
                dfs(s.substr(i,s.length()-i),cur,res);
                cur.pop_back();
            }
        }
 
    }
 
};
```
