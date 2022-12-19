```
class Solution {
    public int findSpecialInteger(int[] arr) {
        for (int count = 1, i = 1; i < arr.length; i++) {
            count = arr[i] == arr[i - 1] ? count + 1 : 1;
            if (count > arr.length / 4) {
                return arr[i];
            }
        }
        return arr[0];
    }
}
```
