```java
class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int n = A.length;
        List<Integer> LA = new ArrayList<>();
        List<Integer> LB = new ArrayList<>();
        HashMap<Integer, Integer> res = new HashMap<>();
        for (int i = 0; i < n * n; i ++) {
            if (A[i / n][i % n] == 1) LA.add(i / n * 100 + i % n);
            if (B[i / n][i % n] == 1) LB.add(i / n * 100 + i % n);
        }
        for (int a : LA) {
            for (int b : LB) {
                res.put(a - b, res.getOrDefault(a - b, 0) + 1);
            }
        }
        int ans = 0;
        for (int value : res.values()) {
            ans = Math.max(ans, value);
        }
        return ans;
    } 
}
```