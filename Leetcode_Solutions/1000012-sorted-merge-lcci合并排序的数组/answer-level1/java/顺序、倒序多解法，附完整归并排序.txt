- 同 [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)
- 归并排序的 归并 部分

# 本题代码

## 顺序填入

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    int[] temp = new int[m + n];
    int ti = 0, i = 0, j = 0;
    while (i < m && j < n) {
        temp[ti++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    }
    while (i < m) temp[ti++] = nums1[i++];
    while (j < n) temp[ti++] = nums2[j++];
    System.arraycopy(temp, 0, nums1, 0, m + n);
}
```


## 倒序填入

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    int ti = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        nums1[ti--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
    while (i >= 0) nums1[ti--] = nums1[i--];
    while (j >= 0) nums1[ti--] = nums2[j--];
}
```

# 归并排序

```java
public void mergeSort(int[] array, int left, int right) {
    if (right <= left) return;
    int mid = left + ((right - left) >> 1); // (left + right) / 2

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

private void merge(int[] arr, int left, int mid, int right) {
    int[] temp = new int[right - left + 1]; // 中间数组
    int i = left, j = mid + 1, k = 0;
    // i: 左数组指针, j: 右数组指针, k: 结果数组指针

    // 一次遍历挪入结果数组
    while (i <= mid && j <= right) {
        // 较小者挪入结果数组，并移动指针    
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    // 放剩余部分
    while (i <= mid)   temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // 放回 arr
    for (int p = 0; p < temp.length; p++) {
        arr[left + p] = temp[p];
    }
    // 也可以用 System.arraycopy(a, start1, b, start2, length)
}
```

