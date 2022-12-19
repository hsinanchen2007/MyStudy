### 解题思路
二维数组转一维数组

### 代码

```java
class Vector2D {
	private static int[] baseArr = new int[] {};
	private static int index = 0;
	public Vector2D(int[][] v) {
		for (int[] row : v) {
			baseArr = Arrays.copyOf(baseArr, baseArr.length + row.length);
			System.arraycopy(row, 0, baseArr, baseArr.length - row.length, row.length);
		}
	}
	public int next() {
		return index < baseArr.length ? baseArr[index++] : -1;
	}

	public boolean hasNext() {
		return index < baseArr.length;
	}
}
```