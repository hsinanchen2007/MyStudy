### 解题思路
依次遍历每个人判断是不是名人，
1.其他人不认识名人
2.名人认识其他人
判断失败，继续判断下一个是不是名人!

### 代码

```java
/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
   public int findCelebrity(int n) {
		for (int i = 0; i < n; i++) {
			boolean finded = true;
			for (int j = 0; j < n; j++) {
				// 其他人j不认识名人i 或者   名人i认识其他人j
				if (!knows(j, i) || (i != j && knows(i, j))) {
					finded = false;
					break;
				}
			}
			if (finded) {
				return i;
			}
		}
		return -1;
	}
}
```