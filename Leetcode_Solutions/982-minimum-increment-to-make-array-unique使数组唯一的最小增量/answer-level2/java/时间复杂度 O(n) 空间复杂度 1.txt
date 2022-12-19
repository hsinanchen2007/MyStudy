思路：
  将数组排序后，遍历每个值，将A[i]的值与A[i-1]进行比较，如果A[i]<=A[i-1]，对A[i]进行move操作，确保每个值都大于比前一个位置，即A[i]>A[i-1].
```
  public int minIncrementForUnique(int[] A) {
    if (A == null || A.length == 0) {
      return 0;
    }
    Arrays.sort(A);
    int cnt = 0;
    for (int i = 1; i < A.length; i++) {
      if (A[i - 1] >= A[i]) {
        cnt += A[i - 1] - A[i] + 1;
        A[i] = A[i - 1] + 1;
      }
    }
    return cnt;
  }
```
