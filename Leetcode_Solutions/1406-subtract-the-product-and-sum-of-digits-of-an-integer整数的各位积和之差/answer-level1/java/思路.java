### 解题思路
此处撰写解题思路
我的思路:
    用n大于0作为循环的条件。每一次将n取出最后一位数，进行乘法累乘，加法累加，
    最后返回的就是用乘法的值减去加法的值;

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int sum=0;
        int avg=1;
        while(n>0){
            int a=n%10;
            sum=sum+a;
            avg=avg*a;
            n=n/10;
        }
        return avg-sum;
    }
}
```