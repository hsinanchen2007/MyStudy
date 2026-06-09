### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public boolean isSelfCrossing(int[] x) {
	if (x.length <= 3) return false;
		int i = 3;
		if (x[i - 1] > x[i - 3]) {
			if (x[i] == x[i - 2]) x[i - 1] -= x[i - 3];
		} else if (x[i] >= x[i - 2]) return true;
		while (++i < x.length) {
			if (x[i-1] > x[i - 3]) {
				if (x[i] == x[i - 2]) x[i - 1] -= x[i - 3];
				else if (x[i] < x[i - 2])
					if (x[i] >= x[i - 2] - x[i - 4]) x[i - 1] -= x[i - 3];
			} else if (x[i] >= x[i - 2]) return true;
		}
		return false;
	}
}
```