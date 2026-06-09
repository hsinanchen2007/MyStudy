
```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == arr.length) {
            return arr;
        }
        int[] d = new int[10001];
        for (int i : arr) {
            d[i]++;
        }
        int[] result = new int[k];
        int current = 0;
        for (int i = 0; current < k; i++) {
            for (int j = 0, l = d[i]; current < k && j < l; j++) {
                result[current++] = i;
            }
        }
        return result;
    }
}
```
