- [思路出处](https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/solution/java-chao-yue-9966xiang-xi-jie-xi-by-flychenkai/)
- 开头排序
- 先反好该反的，同时维护最小值索引
- 最后一次遍历累计
```java
public int largestSumAfterKNegations(int[] arr, int k) {
    Arrays.sort(arr); // asc: 负数...0..0..正数
    int sum = 0, len = arr.length, minIndex = 0; // 初始第一个最小
    while (k > 0) {
        arr[minIndex] = -arr[minIndex]; // 最小者取反
        k--;
        // 维护最小值索引
        // 若后面还有数，则看当前的与下一个谁更小
        if (minIndex + 1 < len && arr[minIndex] > arr[minIndex + 1]) minIndex++;
    }
    for (int i : arr) sum += i;
    return sum;
}
```
