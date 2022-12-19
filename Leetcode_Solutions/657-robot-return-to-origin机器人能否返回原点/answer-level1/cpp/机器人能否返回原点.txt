```
class Solution {
public:
    bool judgeCircle(string moves) {
        int UD = 0,LR = 0;
        for(char c : moves){
            switch(c){
                case 'U':   UD+=1;  break;
                case 'D':   UD-=1;  break;
                case 'L':   LR+=1;  break;
                case 'R':   LR-=1;  break;
            }
        }
        return !UD&&!LR ? true : false ;
    }
};
```