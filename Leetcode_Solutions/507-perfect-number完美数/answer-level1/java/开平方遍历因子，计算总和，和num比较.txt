暴力遍历的话会超时。
所以我们只遍历到num的开平方，同时对遍历的每个能被num整除的数i加上num/i，就是另一个因子。这个地方要注意特殊条件“因子不能等于num”和特殊值“1”。
对所有因子求和后，比对是否和num相等。
```
class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num == 1){
            return false;
        }
        int sum = 0;
        int i = 2;
        for(; i < Math.sqrt(num); i++) {
            if(num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        if(i * i == num){
            sum += i;
        }
        sum += 1;
        return sum == num;
    }
}
```