### 解题思路
动态规划，自下向上

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> col(p.size()+1);
        vector<vector<bool> > tempGrid(s.size()+1,col);
        tempGrid[s.size()][p.size()] = true;
        for(int i=s.size();i>=0;i--){
            for(int j=p.size()-1;j>=0;j--){
                bool fistMatch = (i<s.size() && (p[j]==s[i] || p[j]=='.'));
                if(j+1<p.size() && p[j+1] == '*'){
                    tempGrid[i][j] = tempGrid[i][j+2] || fistMatch && tempGrid[i+1][j];
                }else{
                    tempGrid[i][j] = fistMatch && tempGrid[i+1][j+1];
                }
            }
        }

       
        return tempGrid[0][0];
    }
};
```