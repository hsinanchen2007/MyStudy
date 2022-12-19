![2019123103.PNG](https://pic.leetcode-cn.com/2823ecc2e9dadd465ab860716081a8a21e8d33dfc69cfc6d026123c5ef55dcd2-2019123103.PNG)

### 解题思路
对整数n取余操作，然后对余数分别进行相加和相乘操作
每进行一次取余后，n等于原来的n取整。
### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int sumOfAdd=0;
        int sumOfMul = 1;
        while(n>0) {
        	sumOfAdd += n%10;
        	sumOfMul *= n%10;
        	n = n/10;
        }
    	return (sumOfMul-sumOfAdd);
    }
}
```