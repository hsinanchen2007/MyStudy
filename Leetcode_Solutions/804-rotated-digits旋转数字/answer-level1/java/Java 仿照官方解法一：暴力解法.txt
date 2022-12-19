### 解题思路
仿照的是官方解法方法一：暴力解法	动态规划目前还看不太懂
![QQ截图20200131181350.png](https://pic.leetcode-cn.com/992cd03e9efbce75ee586b0ad3c16282bdbc0a37a376f51fa9762643c4da3846-QQ%E6%88%AA%E5%9B%BE20200131181350.png)
需要注意的一点是good函数第一行和第二行的次序问题
我本来写的
```java
int e = n%10;
if(e==0) return b;
```
上面的思路其实是错误的，会减少结果的数量
因为当 b 为 false 时，只要 n 是 10 的倍数，那么就会直接返回 false
我们想要的是 n 这个数字的每一位都要被检测到


### 代码

```java
class Solution {
    public int rotatedDigits(int N) {
        int result = 0;
		for(int i=1;i<=N;i++) {
			if(good(i, false)) result++;
		}
		return result;
    }
	public boolean good(int n, boolean b) {
		if(n==0) return b;
		int e = n%10;
		if(e==3 || e==4 || e==7) return false;
		if(e==0 || e==1 || e==8) return good(n/10, b);
		return good(n/10, true);
	
    }
}
```