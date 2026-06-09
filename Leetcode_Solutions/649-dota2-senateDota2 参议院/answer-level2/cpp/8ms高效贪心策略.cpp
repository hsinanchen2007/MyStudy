```
class Solution {
public://执行用时 :8 ms, 在所有 C++ 提交中击败了98.17%的用户
    int r,d,power;
    int rm,dm;
    bool vis[10000];//标记已被禁止权力的议员
    string predictPartyVictory(string senate) {
        rm = count(senate.begin(),senate.end(),'R');//记录r的总数量
        dm = senate.length() - rm;//记录d的总数量
        while(true) {//轮选
            for(int i=0;i<senate.length();i++) {
                if(!vis[i]) {
                    if(power>0) { //power用来记录当前的剩余权力数（正数为r,负数为d）
                        if(senate[i]=='R') power++;
                        else vis[i] = true,power--,d++;
                        if(d==dm) return "Radiant";
                    }else if(power<0){
                        if(senate[i]=='D') power--;
                        else vis[i] = true,power++,r++;
                        if(r==rm) return "Dire";
                    }else {
                        if(senate[i]=='R') power++;
                        else power--;
                    }
                }
            }
        }
        return "";
    }
};
```
