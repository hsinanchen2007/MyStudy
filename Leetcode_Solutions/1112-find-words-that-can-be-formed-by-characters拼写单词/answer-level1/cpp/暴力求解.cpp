### 解题思路
遍历求解，用visit数组记录是否已经用过这个字母拼写

### 代码

```cpp
#include<cstring>
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int N = chars.length();
        int raw= words.size();
        int col= words[0].size();
        int visit[N] = {1};
        int ans = 0;
        char s[1000];
        int cnt = 0;
        int m=0;
        for(int i=0;i<raw;i++){
            for(int t=0;t<N;t++)visit[t] = 1;
           // visit[N] = {1};//1表示可以，0表示已经用过
            cnt = 0;//（每个）单词统计
            col = words[i].size();
                for(int j=0;j<col;j++){
                for(int k=0; k<N;k++){
//                    cout<<words[i][j]<<chars[k]<<visit[k]<<endl;
                    if(words[i][j] == chars[k] && visit[k] == 1)  
                    {
                        
                        cnt=cnt+1;
                        visit[k] = 0;
                        break;
                    }
                    
                }
                
                
            }
//            cout<<cnt<<endl;
            if(cnt == col){
                    ans = ans + cnt;
                }
        }
        
        return ans;
    }
};
```