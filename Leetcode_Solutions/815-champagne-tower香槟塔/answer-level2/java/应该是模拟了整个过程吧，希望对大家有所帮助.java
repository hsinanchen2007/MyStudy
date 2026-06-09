```
class Solution {
	public double champagneTower(int poured, int query_row, int query_glass) {
		int len = query_row + 1;
		double[] now = new double[len];
		now[0] = poured;
		for (int i = 1; i < len; i++) {
			double left = 0;
			for (int n = 0; n <= i; n++) {
				double right = (now[n] > 1 ? (now[n] - 1) : 0) / 2;
				now[n] = left + right;
				left = right;
			}
		}
		return now[query_glass] > 1 ? 1 : now[query_glass];
	}
}
```
