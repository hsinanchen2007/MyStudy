维护一个K大小的最大堆。
遍历数组，如果比堆顶（最大值）小，就替换堆顶，然后调整堆。
```
public class Solution {
    void swap(int[] nums, int x, int y) {
        var r = nums[x];
        nums[x] = nums[y];
        nums[y] = r;
    }

    void maxHeapify(int[] nums, int i) {
        if (i > nums.Length - 1) return;
        var left = 2 * i + 1;
        var right = 2 * i + 2;
        if (left < nums.Length && nums[left] > nums[i] && (right >= nums.Length || nums[left] >= nums[right])) {
            swap(nums, i, left);
            maxHeapify(nums, left);
        } else if (right < nums.Length && nums[right] > nums[i] && (left >= nums.Length || nums[right] >= nums[left])) {
            swap(nums, i, right);
            maxHeapify(nums, right);
        }
    }

    void buildHeap(int[] nums) {
        var lastNonLeaf = (nums.Length - 1) / 2;
        for (int i = lastNonLeaf; i >= 0; i--) {
            maxHeapify(nums, i);
        }
    }

    public int[] GetLeastNumbers(int[] arr, int k) {
        if (k == 0) return new int[] { };
        var heap = new int[k];
        Array.Copy(arr, heap, k);
        buildHeap(heap);
        for (int i = k; i < arr.Length; i++) {
            if (heap[0] > arr[i]) {
                heap[0] = arr[i];
                maxHeapify(heap, 0);
            }
        }
        return heap;
    }
}
```
