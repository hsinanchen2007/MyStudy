```
class Solution {
public:
    int climbStairs(int n) {
        int m[4]={1,0,0,0};
        int k=0;
        int r=0;
        do{
            int mk=k&0x3;
            if(k==n){
                r=m[mk];
                break;
            }
            int mk1=(k+1)&0x3;
            int mk2=(k+2)&0x3;
            m[mk1]=m[mk1]+m[mk];
            m[mk2]=m[mk2]+m[mk];
            m[mk]=0;
            k++;
        }while(1);
        return r;
    }
};
```
