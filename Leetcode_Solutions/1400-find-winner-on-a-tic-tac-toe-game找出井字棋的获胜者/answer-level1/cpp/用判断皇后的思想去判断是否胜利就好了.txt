
```
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int sz=moves.size();
        if(sz>=9)return "Draw";
        int cnt[2][4][100];
        memset(cnt,0,sizeof(cnt));
        for(register int i=0;i<sz;++i){
            int x=moves[i][0],y=moves[i][1];
            cnt[i%2][0][y]++,cnt[i%2][1][x]++,cnt[i%2][2][x+y]++,cnt[i%2][3][2-x+y]++;
            int tab[]{y,x,x+y,2-x+y};
            for(register int j=0;j<4;++j)
                if(cnt[i%2][j][tab[j]]==3)return i%2?"B":"A";
        }
        return "Pending";
    }
};
```
