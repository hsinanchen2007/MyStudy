```java
class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        int count = 0;
        Map<Integer, Integer> map = new HashMap<>();
        boolean stopj = false;
        for (int i = 0, j = 0; i < A.length && j < A.length; ) {
            if (!stopj) {
                map.compute(A[j], (key, v) -> v == null ? 1 : v + 1);
            }
            int num = map.size();
            if (num == K) {
                count++;
                int k = j + 1;
                while (k < A.length && map.containsKey(A[k])) {
                    count++;
                    k++;
                }

                map.compute(A[i], (key, v) -> v == null ? 0 : v - 1);
                if (map.get(A[i]) == 0) {
                    map.remove(A[i]);
                }
                i++;
                stopj = true;
            } else {
                stopj = false;
                j++;
            }
        }
        return count;
    }
}
```