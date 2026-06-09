打表获取进制位n对应的最大值，空间换时间。

可以优化把`size`变量去掉，还可以把10改为9，100改为99等，为不影响可阅读性，大家自行发挥。
```java
class Solution {
    public int[] printNumbers(int n) {
		//因为n为正整数，所以最小为10，也可以把10改为9，100改为99等
		int[] map = { 10, 100, 1000, 10_000, 100_000, 1_000_000, 10_000_000,
 				100_000_000, 1_000_000_000, Integer.MAX_VALUE };
		int size = map[n-1];
		int[] ans = new int[size - 1];
		for (int i = 1; i < size; i++) {
			ans[i - 1] = i;
		}
		return ans;
    }
}
```