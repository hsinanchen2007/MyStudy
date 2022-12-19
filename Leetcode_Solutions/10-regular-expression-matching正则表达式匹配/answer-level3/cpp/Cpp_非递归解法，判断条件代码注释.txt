```
class Solution {
public:
    
    bool dfs(string& s,string& p){
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<bool>> memo = vector<vector<bool>>(s.size()+1,vector<bool>(p.size()+1,0));
        //自底向上
        //memo[sSize][pSize] 对应  “” 匹配 “”
        memo[sSize][pSize] = 1;
        for(int i = sSize;i>=0;i--){
            for(int j = pSize-1;j>=0;j--){
                                //s子串 非空 && （同字符匹配 || 任意字符通配）
                bool headMatch =i<sSize && (p[j] == s[i] || p[j] == '.');
                if(j+1 <pSize && p[j+1] =='*' ){
                                //* 匹配0个字符(即越过当前匹配符和*)  ||  *匹配多个字符
                    memo[i][j] = memo[i][j+2] || (headMatch && memo[i+1][j]);
                }else{
                                //首字符匹配 && 下一对匹配
                    memo[i][j] =headMatch && memo[i+1][j+1];
                }
            }   
        }
        return memo[0][0];
    }
    bool isMatch(string s, string p) {
        return dfs(s,p);
    }
};
```
