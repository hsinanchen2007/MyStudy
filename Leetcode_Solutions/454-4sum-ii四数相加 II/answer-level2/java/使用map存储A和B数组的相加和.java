### 解题思路
首先遍历A数组和B数组，将加和存储在在map中，key为加和，value为相同key的次数，初始次数为1
然后遍历C数组和D数组，判断0 - C[i] - D[j]是否在map中，若存在，取出对应的value，然后累加起来。

### 代码

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        //优化暴力解决
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                int key = A[i] + B[j];
                if (map.containsKey(key))
                    map.put(key,map.get(key) + 1);
                else
                    map.put(key,1);
            }
        }
        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < D.length; j++) {
                int key = 0-C[i]-D[j];
                if (map.containsKey(key)){
                    count = count + map.get(key);
                }
            }
        }
        return count;
    }
}
```