### 解题思路
位比较O（n），累加

如果是1，那么，a,b 都是0，+1
如果是0, 那么 a，b有1减1
### 代码

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        if(c==0 && a==0 && b==0) {
			return 0;
		}
		
		int rst = 0;
		if(c%2 != (a%2 | b%2)) {
			if(c%2 == 1) {
				rst = 1;
			}	else {
				rst+=a%2+b%2;
			}
		}
		return rst + minFlips(a/2, b/2, c/2);
		
		
	}
}
```