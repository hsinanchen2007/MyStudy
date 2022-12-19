```
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0){
            return true;
        }
        int i = 0;
        int j = (int)sqrt(c);
        int tmp = 0;
        while(i <= j){
            tmp = c - j*j;
            if(tmp == i*i){
                return true;
            }else if(tmp < i*i){
                j --;
            }else{
                i ++;
            }
        }
        return false;
    }
};
```
