### 执行结果
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
递归解决不了问题，容易超出时间限制，选择用**自顶向上**的**动态规划**算法。

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n==0 ||n==1) {
			return n;
		}else if(n==2) {
			return 1;
		}else {
			int prev=1,curr=1;
			int sum=0;
			for(int i=3;i<=n;i++) {
				sum=prev%1000000007+curr%1000000007;
				prev=curr%1000000007;
				curr=sum%1000000007;
			}
			return sum%1000000007;
		}
    }
}
```