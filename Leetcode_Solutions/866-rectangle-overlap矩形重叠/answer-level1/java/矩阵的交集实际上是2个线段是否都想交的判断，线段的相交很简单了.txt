### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
		if ((rec2[0] >= rec1[0] && rec2[0] < rec1[2]) || (rec2[2] > rec1[0] && rec2[2] <= rec1[2])
				|| (rec2[0] <= rec1[0] && rec2[2] >= rec1[2])) {
			
			if ((rec2[1] >= rec1[1] && rec2[1] < rec1[3]) || (rec2[3] > rec1[1] && rec2[3] <= rec1[3])
					|| (rec2[1] <= rec1[1] && rec2[3] >= rec1[3])) {
				return true;
			}

		}

		return false;

	}


}
```