### 解题思路
1. 先定义数组`min,max`分别用来存储同行中最小元素和同列中最大元素，并将其填充；
2. 进入两层循环，对矩阵`matrix`进行遍历；
3. 比较每行中当前最小值和各元素大小，返回小的那个数；
4. 比较每列中当前最大值和各元素大大，返回大的那个数；
5. 对`min`和`max`中元素进行比较，若对应位置元素相等，则作为幸运数添加到列表`list`中；
6. 返回列表；

### 代码

```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
		int m = matrix.length;
		int n = matrix[0].length;

		int[] min = new int[m];
		int[] max = new int[n];

		Arrays.fill(min, 10 * 10 * 10 * 10 * 10);
		Arrays.fill(max, 1);

		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				min[i] = Math.min(min[i], matrix[i][j]);
				max[j] = Math.max(max[j], matrix[i][j]);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (min[i] == max[j]) {
					list.add(min[i]);
				}
			}
		}
		return list;
    }
}
```