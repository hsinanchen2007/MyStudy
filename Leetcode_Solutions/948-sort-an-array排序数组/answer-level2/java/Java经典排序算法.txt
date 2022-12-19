经典排序算法总结：[https://blog.csdn.net/qq_40794973/article/details/102863580]()

---
堆排序：[https://blog.csdn.net/qq_40794973/article/details/102880394]()
```
import java.util.ArrayList;
import java.util.List;
class Solution {
    // 不使用一个额外的最大堆, 直接在原数组上进行原地的堆排序
    private void heapSort(int[] arr) {
        int n = arr.length;
        // 注意，此时我们的堆是从0开始索引的
        // 从(最后一个元素的索引-1)/2开始
        // 最后一个元素的索引 = n-1
        //Heapify
        for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
            shiftDown(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);
            shiftDown(arr, i, 0);
        }
    }
    /**
     * @param n 参与排序的数组的长度（最后一个元素的下一个位置）
     * @param k 当前的元素
     */
    private void shiftDown(int[] arr, int n, int k) {
        int e = arr[k];
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && arr[j + 1] > arr[j]) {
                j++;
            }
            //当前节点大于子节点
            if (e >= arr[j]) {
                break;
            }
            arr[k] = arr[j];
            k = j;
        }
        arr[k] = e;
    }
    // 交换堆中索引为i和j的两个元素
    private void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
    public List<Integer> sortArray(int[] nums) {
        List<Integer> res = new ArrayList<>(nums.length);
        heapSort(nums);
        for (int i = 0; i < nums.length; i++) {
            res.add(nums[i]);
        }
        return res;
    }
}
```
有空再写...