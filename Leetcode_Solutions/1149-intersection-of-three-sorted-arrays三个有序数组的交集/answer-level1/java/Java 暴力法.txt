```
import java.util.Arrays;

class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> out = new ArrayList<>();
        for (int i = 0; i < arr1.length; i++) {
            if (isInArr(arr2, arr1[i]) && isInArr(arr3, arr1[i])) {
                Integer tmp = arr1[i];
                out.add(tmp);
            }
        }
        return out;
    }
    
    public static boolean isInArr(int[] arr, int a) {
        for (int i : arr) {
            if (a == i) {
                return true;
            }
        }
        return false;
    }
}
```
