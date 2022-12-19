
1. 我们可以首先对两个数组进行排序。对B数组进行排序的同时，我们需要记录下原始的索引。
2. 当对排序后对数组进行比较时，我们可以取出原始的索引进行填充。
3.  比较时，使用贪心算法。 
由于题目中求的A[i]>B[i]。 那么排序完毕后,A[maxIndex] > B[maxIndex]。如果不满足，此时开启贪心策略，需要将A[minIndex] 放在结果集中，这样就保证A[maxIndex]还能对后续对B[maxIndex]保持统治地位。典型对田忌赛马。

```java

public int[] advantageCount(int[] A, int[] B) {
    if (A == null || B == null) return A;
    // 排序集合A
    Arrays.sort(A);
    // 索引排序
    int[] indexs = quickSort(B);
    int[] ret = new int[A.length];
    int index = B.length - 1;
    int maxIndex = A.length - 1;
    int minIndex = 0;
    while (index >= 0) {
      if (B[index] < A[maxIndex]) {
        ret[indexs[index]] = A[maxIndex];
        maxIndex--;
        index--;
      } else {
        ret[indexs[index]] = A[minIndex];
        index--;
        minIndex++;
      }
    }

    return ret;
  }


  private int[] quickSort(int[] b) {
    int[] indexs = new int[b.length];
    int i = 0;
    while (i < b.length) {
      indexs[i++] = i;
    }
    partition(indexs, b, 0, b.length - 1);
    return indexs;
  }

  private void partition(int[] indexs, int[] arr, int start, int end) {

    if (end <= start) return;

    int r = end;
    int l = start + 1;
    int flag = arr[start];
    while (true) {
      while (r >= start && arr[r] >= flag) {
        r--;
      }
      while (l <= end && arr[l] <= flag) {
        l++;
      }
      if (r <= l) break;
      swap(indexs, l, r);
      swap(arr, l, r);
    }
    swap(indexs, start, l - 1);
    swap(arr, start, l - 1);
    partition(indexs, arr, start, l - 2);
    partition(indexs, arr, l, end);
  }


  private void swap(int[] arr, int l, int r) {
    int temp;
    temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }
```