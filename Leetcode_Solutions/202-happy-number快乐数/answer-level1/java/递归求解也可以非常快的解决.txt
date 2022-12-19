递归求解，观察得到不管什么数字会收敛到一个 个位数，以此作为递归终止条件。如果是快乐数（快乐就完事了），最终会收敛到1*10的N次方，也就是1，7也是快乐数；非快乐数前期会收敛到一个 个位数4（4->16->37->58->89->145->42->20）
```
class Solution {
    public boolean isHappy(int n) {
        if(n==1)return true;
        if(n==4) return false;
        int sum  = 0;
        while(n>0){
            int t = n%10;
            sum=sum+t*t;
            n/=10;
        }
        return isHappy(sum);
    }
}
```
