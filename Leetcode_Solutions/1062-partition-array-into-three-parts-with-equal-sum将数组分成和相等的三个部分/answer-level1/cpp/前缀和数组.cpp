若要等分成三部分，则数组之和`sum`必须要能被`3`整除，且在前缀和数组中，必定先出现一倍`sum/3`，然后二倍`sum/3`。

代码如下

```cpp

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0,size=A.size();
        for(int i=0;i<size;i++){
            sum+=A[i];
            A[i]=sum;
        }
        int avg=sum/3;
        if(sum%3!=0)return false;
        bool onetime=false,twotimes=onetime;
        for(auto i:A){
            if(i==avg)onetime=true;
            else if(i==avg*2 && onetime){
                twotimes=true;
                break;
            }
        }
        return onetime & twotimes;
    }
};

```