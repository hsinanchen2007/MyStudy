### 解题思路


### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int num=n%10;
        int sum=0,mul=1;
        while(n>0){
            num=n%10;
            sum+=num;
            mul*=num;
            n/=10;
        }
        return mul-sum;
    }
}
```