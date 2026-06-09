### 解题思路
只要后一个数大于前一个，就累加。一个if就搞定。
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.55%
的用户
内存消耗 :
42.6 MB
, 在所有 Java 提交中击败了
5.05%
的用户

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length<=1) {
			return 0;
		}
    	int sum=0;
    	for (int i = 1; i < prices.length; i++) {
			if (prices[i-1]<prices[i]) {
				sum+=prices[i]-prices[i-1];
			}		
		}
    	return sum;    
    }
}
```