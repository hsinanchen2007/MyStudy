### 解题方案
- 穷举
- 二分优化

### 方法一：枚举
#### 算法
- 用一个二维数组 pair 统计每一行的 id 以及每一行数字 1 的数量；
- 然后排序，然后输出二维数组 pair 的前 k 个数组下标。
```java []
public int[] kWeakestRows(int[][] mat, int k) {

    int m = mat.length;
    int n = mat[0].length;
    int[][] pair = new int[m][2];

    for (int r = 0; r < m; r++) {
        pair[r][0] = r;                            //记录每一行的下标
        for (int c = 0; c < n; c++) {
            if (mat[r][c] == 1)  pair[r][1]++;     //记录每一行1的数量
        }
    }

    Arrays.sort(pair, (e1, e2) -> e1[1] - e2[1]);  //按1的数量降序排列
    int[] arr = new int[k];
    
    for (int i = 0; i < k; i++) {
        arr[i] = pair[i][0];                       //取前k个下标
    }
    return arr;
}
```
### 复杂度分析
- 时间复杂度：$O(m * n)$，n 为网格 mat 的行数，m 为列数。
- 空间复杂度：$O(k + m)$，

---
### 方法二：二分优化
 1 总是出现在 0 之前。意味着每一行都是一个降序的有序数组。所以 1 的数量就是第一个 0 的下标的大小。
- 问题转化为寻找第一个0的下标。
```java []
public int[] kWeakestRows1(int[][] mat, int k) {

  int m = mat.length;
  int n = mat[0].length;
  int[][] pair = new int[m][2];

  for (int r = 0; r < m; r++) {
      pair[r][0] = r;
      pair[r][1] = binary_search(mat[r], 0, n); // 查找第一个0的下标
  }

  Arrays.sort(pair, (e1, e2) -> e1[1] - e2[1]);
  int[] arr = new int[k];

  for (int i = 0; i < k; i++) {
    arr[i] = pair[i][0];
  }
  return arr;
}
// 查找第一个0的下标
private int binary_search(int[] arr, int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == 1)  l = mid + 1;
        else 		    r = mid;
    }
    return l;
}
```
### 复杂度分析
- 时间复杂度：$O(m  × log(n))$，
- 空间复杂度：$O(k + m)$，

---
感兴趣的伙伴可提供一下 **其他语言或者说任何语言** 的实现代码。