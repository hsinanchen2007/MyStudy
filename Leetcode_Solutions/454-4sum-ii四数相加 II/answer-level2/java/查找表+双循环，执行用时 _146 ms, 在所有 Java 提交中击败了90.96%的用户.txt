执行结果：通过
执行用时 :146 ms, 在所有 Java 提交中击败了90.96%的用户
内存消耗 :56.9 MB, 在所有 Java 提交中击败了95.67%的用户

思路：将数组C，D 任意组合的和存入查找表中， key是和，value 是出现的次数。记录A，B 任意组合的和的负值，然后在查找表中查找是否有对应的值
时间复杂度：O(n^2。
```
public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {

        HashMap<Integer, Integer> map = :new HashMap<>();
        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < D.length; j++) {
                int sum = C[i] + D[j];
                if (map.containsKey(sum)) {
                    map.put(sum, map.get(sum) + 1);
                } else {
                    map.put(sum, 1);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {

                int res = -(A[i] + B[j]);
                if (map.containsKey(res)) {
                    count += map.get(res);
                }

            }
        }

        return count;
    }
```