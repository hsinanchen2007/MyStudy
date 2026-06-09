### 解题思路
dp数组说明： dp[第i个单词][手指1位置][手指2位置] 0-25记录A-Z，26记录该手指未用过

### 代码

```cpp
class Solution {
public:
    int minimumDistance(string word) {
        if (word.size()<=2) return 0;
        int ***dp=new int**[word.size()];
        for (int i=0;i<word.size();i++){
            dp[i]=new int*[27];
            for (int j=0;j<27;j++){
                dp[i][j]=new int[27]{0};
            }
        }
        for (int i=0;i<word.size();i++){
            for (int j=0;j<27;j++){
                for (int k=0;k<27;k++){
                    dp[i][j][k]=10000;
                }
            }
        }
        dp[0][word[0]-'A'][26]=0;
        dp[0][26][word[0]-'A']=0;
        for (int i=1;i<word.size();i++){
            int lastword=word[i-1]-'A';
            int thisword=word[i]-'A';
            for (int j=0;j<=26;j++){
                if (dp[i-1][lastword][j]!=10000){
                    if (j==26){
                        if (dp[i-1][lastword][j]<dp[i][lastword][thisword]){
                            dp[i][lastword][thisword]=dp[i-1][lastword][j];
                            dp[i][thisword][lastword]=dp[i-1][lastword][j];
                        }
                        if ((dp[i-1][lastword][j]+abs(lastword/6-thisword/6)+abs(lastword%6-thisword%6))<dp[i][thisword][j]){
                            dp[i][thisword][j]=dp[i-1][lastword][j]+abs(lastword/6-thisword/6)+abs(lastword%6-thisword%6);
                            dp[i][j][thisword]=dp[i-1][lastword][j]+abs(lastword/6-thisword/6)+abs(lastword%6-thisword%6);
                        }
                    }
                    else{
                        if ((dp[i-1][lastword][j]+abs(lastword/6-thisword/6)+abs(lastword%6-thisword%6))<dp[i][thisword][j]){
                            dp[i][thisword][j]=dp[i-1][lastword][j]+abs(lastword/6-thisword/6)+abs(lastword%6-thisword%6);
                            dp[i][j][thisword]=dp[i-1][lastword][j]+abs(lastword/6-thisword/6)+abs(lastword%6-thisword%6);
                        }
                        if ((dp[i-1][lastword][j]+abs(j/6-thisword/6)+abs(j%6-thisword%6))<dp[i][lastword][thisword]){
                            dp[i][lastword][thisword]=(dp[i-1][lastword][j]+abs(j/6-thisword/6)+abs(j%6-thisword%6));
                            dp[i][thisword][lastword]=(dp[i-1][lastword][j]+abs(j/6-thisword/6)+abs(j%6-thisword%6));
                        }
                    }
                }
            }
        }
        int finalword=word[word.size()-1]-'A';
        int min=INT_MAX;
        for (int i=0;i<=26;i++){
            if (dp[word.size()-1][finalword][i]<min) min=dp[word.size()-1][finalword][i];
        }
        return min;
    }
};
```