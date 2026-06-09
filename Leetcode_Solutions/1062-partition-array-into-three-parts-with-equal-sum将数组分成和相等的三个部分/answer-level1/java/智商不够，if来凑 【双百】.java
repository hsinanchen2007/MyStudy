### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
		int sum = 0;
		for (int i = 0; i < A.length; i++) {
			sum += A[i];
		}

		if (sum % 3 == 0) {
			int part = sum / 3;
			int x = 0, y = 0, z = 0;
			boolean xR = false, yR = false, zR = false;
			int index = 0;
			while ((!xR || x != part) && index < A.length) {
				x += A[index++];
				xR = true;
			}

			while ((!yR || y != part) && index < A.length) {
				y += A[index++];
				yR = true;
			}

			while ((!zR || z != part) && index < A.length) {
				z += A[index++];
				zR = true;
			}
			if (xR && yR && zR && x == y && x == z && x == part) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

}
```