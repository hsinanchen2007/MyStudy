### 执行结果
执行用时0ms,在java中击败了100.0%的用户
内存消耗36.8MB，在java中击败了100%的用户
### 解题思路
![image.png](https://pic.leetcode-cn.com/01798c1015bd6f485881f4c71912c40618683ee214ed9fcf87405c170f2a6be3-image.png)

### 代码

```java
class Solution {
    public int numWays(int n) {
        n=n%1000000007;
		if(n==1||n==0) {
			return 1;
		}else {
			int fibnminusOne=1;
			int fibnminusTwo=1;
			int fibn=0;
			for(int i=2;i<=n;i++) {
				fibn=fibnminusOne+fibnminusTwo;
				fibnminusTwo=fibnminusOne%1000000007;
				fibnminusOne=fibn%1000000007;
			}
			return fibn%1000000007;
		}
    }
}
```