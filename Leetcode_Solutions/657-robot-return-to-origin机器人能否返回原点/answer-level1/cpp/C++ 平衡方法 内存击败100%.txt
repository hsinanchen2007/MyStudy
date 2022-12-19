```
class Solution {
public:
    bool judgeCircle(string moves) 
    {   //分别设置上下和左右的平衡点
        int balanceUD=0;
        int balanceRL=0;
       for(int i=0;i<moves.size();i++)
       {
           if(moves[i]=='U')balanceUD++;
           if(moves[i]=='D')balanceUD--;
           if(moves[i]=='R')balanceRL++;
           if(moves[i]=='L')balanceRL--;
       }
       if(balanceUD==0&&balanceRL==0)
       return true;
       else return false;
    }
};
```
