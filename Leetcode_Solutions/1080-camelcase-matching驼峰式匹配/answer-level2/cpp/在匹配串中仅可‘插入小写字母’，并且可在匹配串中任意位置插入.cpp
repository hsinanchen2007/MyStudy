这里有个地方一开始没注意，就是匹配串不可更改顺序，故这不是一道统计字符的题目
解题思路：
排除除匹配串的字符　检查剩下的字符是否都是小写
```
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int i,j,flag;
        vector<bool> res;
        int curindex=0;
        for(i=0;i<queries.size();i++){
            flag=0;
            curindex=0;
            for(j=0;j<queries[i].length();j++){
                if(curindex<pattern.length()&&queries[i][j]==pattern[curindex]){
                    curindex++;
                }
                else if(queries[i][j]>='A'&&queries[i][j]<='Z'){
                    flag=1;
                    break;
                }
            }
            if(flag==1||curindex<pattern.length()){
                res.push_back(false);
            }
            else res.push_back(true);
        }
        return res;
    }
};
```
