### 解题思路
思路简单+实现简单

### 代码

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        //Hash
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        //保存元组的个数
        int res = 0;

        //A+B数组的和
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                int sumAb = A[i] + B[j];
                if (map.containsKey(sumAb)) {
                    map.put(sumAb, map.get(sumAb)+1);
                } else {
                    map.put(sumAb, 1);
                }
            }
        }

        //找C+D数组的和
        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < D.length; j++) {
                int sumCd = -(C[i] + D[j]);
                if (map.containsKey(sumCd)) {//找到了 统计组和
                    res += map.get(sumCd);
                }
            }
        }

        return res;
    }
}
```