建立一个3*3数组，将vector中对应的元素按A:1,B:-1的规则，然后根据位置再进行判断。
```
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int a[3][3]={0};
        for(size_t i=0;i<moves.size();i++){
                if(i%2==0)
                a[moves[i][0]][moves[i][1]]=1;
                else
                a[moves[i][0]][moves[i][1]]=-1;
        }
        if(moves.size()<5)
            return "Pending";
        for(int i=0;i<3;i++){
            if(a[i][0]+a[i][1]+a[i][2]==3 || a[0][i]+a[1][i]+a[2][i]==3)
            return "A";
            else if(a[i][0]+a[i][1]+a[i][2]==-3 || a[0][i]+a[1][i]+a[2][i]==-3)
            return "B";
        }
        if((a[0][0]+a[1][1]+a[2][2]==3)||(a[0][2]+a[1][1]+a[2][0]==3))
            return "A";
        if((a[0][0]+a[1][1]+a[2][2]==-3)||(a[0][2]+a[1][1]+a[2][0]==-3))
            return "B";
        if(moves.size()<9)
        return "Pending";
        else
        return "Draw";
        
    }
};
```
