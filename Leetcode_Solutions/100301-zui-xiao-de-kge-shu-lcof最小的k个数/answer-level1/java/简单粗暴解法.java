```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Arrays.sort(arr);
        int [] arrs = new int[k];
        for (int i = 0; i < arrs.length ; i++) {
            arrs[i] = arr[i];
        }
        return arrs;
    }
}
```
