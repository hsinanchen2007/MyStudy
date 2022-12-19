1. 实现计算好每个字符到任意字符的路劲即可,最短的距离，即为直走两个方向（左上，或者右下），不允许出现回头路。
2. 依次计算两个相邻字符的路径即可。
3. 值得注意的是任何字母到字母z的路径一定要先走左右，再走上下；字母z到任意字母的路径一定是先走上下，再走左右；

```
class Solution {
public:    
    string alphabetBoardPath(string target) {
        vector<vector<string>> next(26,vector<string>(26,""));
        string ans;
        
        
        /*initial*/
        for(int i = 0;i < 26; ++i){
            for(int j = 0;j < 26; ++j){
                string instructions;
                int xMove = (i/5) - (j/5);
                int yMove = (i%5) - (j%5);
                if(j < 25){
                    if(xMove > 0){
                        instructions += string(xMove,'U');
                    }else{
                        instructions += string(abs(xMove),'D');
                    }
                    if(yMove > 0){
                        instructions += string(yMove,'L');
                    }else{
                        instructions += string(abs(yMove),'R');
                    }
                }else{
                    /*if target is z*/
                    if(yMove > 0){
                        instructions += string(yMove,'L');
                    }else{
                        instructions += string(abs(yMove),'R');
                    }
                    if(xMove > 0){
                        instructions += string(xMove,'U');
                    }else{
                        instructions += string(abs(xMove),'D');
                    }
                }
                instructions += "!";
                next[i][j] = instructions;
            }
        }
        
        ans += next[0][target[0]-'a'];
        for(int i = 0;i < target.size()-1; ++i){
            ans += next[target[i]-'a'][target[i+1]-'a'];
        }
        
        return ans;
    }
};
```