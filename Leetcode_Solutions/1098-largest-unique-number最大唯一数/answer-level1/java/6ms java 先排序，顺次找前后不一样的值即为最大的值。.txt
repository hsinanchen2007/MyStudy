先排序，顺次找前后不一样的值即为最大的值。

```
class Solution {
    public static int largestUniqueNumber(int[] A) {
        if (A.length == 1) {
            return A[0];
        }
        Arrays.sort(A);
        int max;
        Set<Integer> set = new HashSet<>();
        for (int i = A.length - 1; i >= 0; i--) {
            max = A[i];
            if (!set.contains(max) && i==0){
                return max;
            }
            if (!set.contains(max) && A[i - 1] != max) {
                System.out.println(max);
                return max;
            }
            set.add(max);
        }
        //if ()
        return -1;
    }
}
```
