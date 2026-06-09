### 解题思路
没有什么高端操作，数字范围为 1 ~ 1000，所以可以用一个二维数组 res 存储结果。
其中：res[i][0] 为数字本身的值，res[i][1] 为数字的权值。
再来对数组进行题目要求的升序排序，最终返回 res[k - 1][0] 即可。

### 代码

```java
class Solution {
    public int getKth(int lo, int hi, int k) {
        int[][] res = new int[hi - lo + 1][2];
        for(int i = lo;i <= hi;i++) {
            res[i - lo][0] = i;
        }
        for(int i = 0;i < res.length;i++) {
            res[i][1] = calculate(res[i][0]);
        }
        Arrays.sort(res, new Comparator<int[]>() { 
	    @Override
	    public int compare(int[] o1, int[] o2) {
		if(o2[1] != o1[1]) return o1[1] - o2[1]; /* 权值不同，按照权值排序 */
		return o1[0] - o2[0]; /* 否则，按照数字本身的值排序 */
	    }
        });
        return res[k - 1][0];
    }

    private static int calculate(int n) { /* 获取权值 */
	int ans = 0;
	while(n > 1) {
	    if(n % 2 == 0) n /= 2;
	    else n = 3 * n + 1;
	    ans++;
	}
	return ans;
    }
}
```