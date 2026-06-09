```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        sort(arr, 0, arr.length - 1);
        int[] arrNew = new int[k];
        System.arraycopy(arr, 0, arrNew, 0, k);
        return arrNew;
    }
    private static void sort(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int[] lr = partition(arr, left, right);
        sort(arr, left, lr[0]);
        sort(arr, lr[1], right);
    }

    private static int[] partition(int[] arr, int left, int right) {
        swap(arr, left, (int) (Math.random() * (right - left + 1) + left));
        int base = arr[left];

        int i = left;
        int j = right;
        int cur = i;

        while (cur <= j) {
            if (arr[cur] == base) {
                cur++;
            } else if (arr[cur] < base) {
                swap(arr, cur++, i++);
            } else {
                swap(arr, cur, j--);
            }
        }
        return new int[]{i - 1, j + 1};
    }

    private static void swap(int[] arr, int i, int j) {
        if (i != j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
```
