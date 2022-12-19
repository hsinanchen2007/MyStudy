```
class Solution {
public:
    int rotatedDigits(int N) {
        int num=0;
        for(int i=1;i<=N;++i){
            if(goodNum(i)) num++;
        }
        return num;
    }
    bool goodNum(int n){
        bool flag1=false,flag2=true;
        while(n>0){
            if(n%10==3||n%10==4||n%10==7){
                flag2=false;
                break;
            }
            if(n%10==2||n%10==5||n%10==6||n%10==9) flag1=true;
            n/=10;
        }
        return flag1&&flag2;
    }
};
```
