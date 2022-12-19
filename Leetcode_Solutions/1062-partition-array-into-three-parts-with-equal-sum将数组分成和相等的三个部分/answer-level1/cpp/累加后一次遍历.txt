先找到三个数组，把剩下的累加，如果为0，说明原数组和为3的倍数，可以省去前面的判断。
```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int x=0,y=0,sum=0;//x为累加之和，y为找到几个部分
        for(auto it=A.begin();it<A.end();it++){
            sum+=*it;
        }
        sum/=3;
        for(auto it=A.begin();it<A.end();it++){
            x+=*it;
            if(x==sum && y<3){
                x=0;
                y+=1;
            }
        }
        if(y==3 && x==0) return true;
        else return false;
    }
};
```
