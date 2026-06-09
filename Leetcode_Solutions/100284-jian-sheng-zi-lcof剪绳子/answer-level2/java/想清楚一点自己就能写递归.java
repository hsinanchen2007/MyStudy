1:绳长为2 剪后积为1
2:绳长为3 剪后积为2
3:绳长为4 剪后积为4
如果绳长大于4那么绳子剪得段的最大长度必为3*x*(4)*(2)
意思就是绳子可以剪成x段3的和最多一段2的及最多一段4的，这样得到的积最大
(2和四仅出现在最后剩下的一段为2或者4)
```
class Solution {
    public int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        return cutt(n);
    }
    public static int cutt(int n){
        if(n==2) {
            return 2;
        }else if(n==3) {
            return 3;
        } else if(n==4) {
            return 4;
        }else{
            return 3*cutt(n-3);
        }
    }
}
```
