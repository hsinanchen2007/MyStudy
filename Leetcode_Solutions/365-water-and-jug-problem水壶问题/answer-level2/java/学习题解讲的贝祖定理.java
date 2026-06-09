### 解题思路
此处撰写解题思路
1. 辗转相除得最大公约数gcd
2. 在0~x+y之内，若z是gcd的倍数，则返回true，否则false
### 代码

```java
class Solution {
    public int gcd(int a, int b) {
		if (a == 0) return b;
		if (a > b) return gcd(b, a);
		return gcd(a, b%a);
	}
	
    public boolean canMeasureWater(int x, int y, int z) {
    	if (z==0) return true;
    	if (z > x+y) return false;
    	return z % this.gcd(x, y) == 0;
    }
}
```