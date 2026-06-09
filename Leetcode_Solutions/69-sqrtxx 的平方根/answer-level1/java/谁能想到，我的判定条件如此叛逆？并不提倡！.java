### 解题思路
此处撰写解题思路
可能有溢出，那加上一个判定条件吧！
### 代码

```java
class Solution {
    public int mySqrt(int x) {
		if (x == 1 || x == 0) return x;
		for (int i=1; i<=x/2; ++i) {
			// 这样会有溢出
			if (i*i<=x && (i+1)*(i+1)>x||(i+1)*(i+1)<0) return i;
		}
		return 0;
    }
}
```