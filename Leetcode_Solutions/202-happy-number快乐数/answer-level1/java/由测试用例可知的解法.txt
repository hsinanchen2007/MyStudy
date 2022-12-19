```
class Solution {
    public boolean isHappy(int n) {
        if(n==1){
            return true;
        }
        while(n>6){ //通过测试用例知道小于7的都不符合条件
            int sum=0;
            while(n>0){
                int e=n%10;
                sum+=e*e;
                n/=10;
            }
            if(sum==1){
                return true;
            }
            n=sum;
        }
        return false;
    }
}
```
