2被归入需要借位，因为2本身可能被借位变成了1；如果借位是最高位，直接退出，不借位
```
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int tmp = 1;
		for (int i = n, j = 0; i > 0; i /= 10, j++) {
			int num = i % 10;
			if (num < 3) {
				if (i/10 == 0) {
					break;
				}
				tmp += 3 * Math.pow(10, j);
			} else {
				tmp += Math.pow(10, j);
			}
		}
		return new int[] { tmp, n - tmp };
    }
}
```
