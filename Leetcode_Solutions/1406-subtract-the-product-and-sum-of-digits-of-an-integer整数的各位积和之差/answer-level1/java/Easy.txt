### 解题思路
题目设置条件n范围不大，sum值不会变0，故直接累加就好。
用while来循环，n/10等于0终止，乘积为各位余数的乘积。

执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
36.3 MB
, 在所有 Java 提交中击败了
5.02%
的用户
### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int sum=n%10+n/10%10+n/100%10+n/1000%10+n/10000%10;
    	int product=n%10;
    	while (n/10!=0) {
    		n/=10;
			product*=n%10;
		}
    	return product-sum;
    }
}
```