### 解题思路
按照题意加加减减就可以了

### 代码

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        int f=0,s=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R'){
                s++;
            }else if(moves[i]=='U'){
                f++;
            }else if(moves[i]=='L'){
                s--;
            }else if(moves[i]=='D'){
                f--;
            }
        }
        if(f==0&&s==0){
            return true;
        }
        return false;
    }
};
```