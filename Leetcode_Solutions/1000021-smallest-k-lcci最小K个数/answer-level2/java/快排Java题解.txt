```
class Solution {
    public int[] smallestK(int[] arr, int k) {
        int[] res = new int[k];
        if (arr == null || arr.length == 0 || k <= 0) return res;
        quickSort(arr, 0, arr.length - 1, k);
        for (int i = 0; i < k; i++) {
            res[i] = arr[i];
        }
        return res;
    }

    private void quickSort(int[] array, int begin, int end, int k) {
        if (begin > end) return;
        int left = begin;
        int right = end;
        int pivot = array[left];
        while (left < right) {
            while (array[right] >= pivot && left < right) {
                right--;
            }
            while (array[left] <= pivot && left < right) {
                left++;
            }
            if (left < right) {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }
        array[begin] = array[left];
        array[left] = pivot;
        if (k - 1 == left) {
            return;
        } else if (k - 1 > left) {
            quickSort(array, left + 1, end, k);
        } else {
            quickSort(array, begin, left - 1, k);
        }
    }
}
```
