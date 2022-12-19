分析：本题首先可以考虑采用暴力法解决，从左至右遍历数组，对于每一项都可以找到第一个比它大的元素，图解如下。![leetcode001.png](https://pic.leetcode-cn.com/7917c52472143a1a220912e2763c870980b7058ac73acc180a3222657eaffe54-leetcode001.png)
现在我们思考如何提高算法的效率。首先本题的时间复杂度O(n2)是无法继续优化了的。无论什么方法都无法降低时间复杂度。那我们就考虑如何高效的利用75之前已经得出的结果。这时我想到了动态规划。把之前得出的结果存储在数组中然后再加以利用。而为了能使这些值有利于我们作比较。我们只好采用从右至左方式遍历数组。
设有数组T，存储着目标数组长度为len，有step数组，存储着结果，长度也为len
当算法运行到T[i]时，从i+1至len-1的结果已经得出由此可得
1. 设j=i
2. 若j < len,则j++
3. 若T[j] > T[i]，则step[i] = j - i;跳至2.
4. 若step[j]==0，则step[i] = 0;跳至2.
5. 否则j = 就+ step[j];
具体执行如图所示
![leetcode001.png](https://pic.leetcode-cn.com/abe303df0b9fca7dba1a71160a4f9a964534f7f613b5bd094557adf98bbd37b7-leetcode001.png)

```
public int[] dailyTemperatures(int[] T) {
		int len = T.length;
		int[] step = new int[len];
		step[len - 1] = 0;
		int j;
		for (int i = len - 2; i >= 0; i--) {
			j = i + 1;
			while (j < len) {
				if (T[j] > T[i]) {
					step[i] = j - i;
					break;
				} else if (step[j] == 0) {
					step[i] = 0;
					break;
				} else {
					j += step[j];
				}
			}
		}
		return step;
	}
```
