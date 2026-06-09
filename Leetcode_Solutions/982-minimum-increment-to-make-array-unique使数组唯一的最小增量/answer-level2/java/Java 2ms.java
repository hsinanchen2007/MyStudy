### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

	public int minIncrementForUnique(int[] A) {
		if (A.length == 0) {
			return 0;
		}
		int max = 0;
		int min = Integer.MAX_VALUE;
		for (int num : A) {
			if (num > max) {
				max = num;
			}
			if (num < min) {
				min = num;
			}
		}
		int[] countmap = new int[max + A.length - min];
		for (int num : A) {
			countmap[num - min]++;
		}
		int opnum = 0;
		for (int num = min; num < countmap.length; num++) {
			int del = countmap[num - min] - 1;
			if (del > 0) {
				countmap[num + 1 - min] += del;
				opnum += del;
			}
		}
		return opnum;
	}

}
```