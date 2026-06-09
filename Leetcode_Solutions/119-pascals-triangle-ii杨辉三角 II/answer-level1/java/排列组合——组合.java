### 解题思路
    /***
     *       1
     *      1 1
     *     1 2 1
     *    1 3 3 1
     *   1 4 6 4 1
     * ...
     * 1 7 21 35 35 21 7 1
     *
     *             7
     * C(1, 7) =  -----
     *             1!
     *
     *
     *             7*6
     * C(2, 7) =  ------
     *             2!
     *
     *             7*...*(7 - i + 1)
     * C(i, 7) =  ------------------
     *             i!
     *
     *                            7 - (i + 1) + 1
     * C(i + 1, 7) =  C(i, 7) *  -----------------
     *                               i + 1
     *
     * 以上 i <= 7
     * 
     * 
     * 
     * </p>
     * 令：k > 0, i < k + 1
     * row(k, 0) = 1
     * row(k, i) = row(k, i-1) * (k - i + 1) / i
     * 
     * 则：
     * row(k, 1) = 1 * (7 - 1 + 1) / 1 = 7
     * row(k, 2) = 7 * (7 - 2 + 1) / 2 = 7 * 6 / 2 = 21
     * row(k, 3) = 21 * (7 - 3 + 1) / 3 = 21 * 5 / 3 = 35
     */

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>(rowIndex + 1);
        result.add(1);

        for (int i = 1; i < rowIndex + 1; i++) {
            long tmp = result.get(i - 1).longValue() * (rowIndex - i + 1);
            result.add((int) (tmp / i));
        }
        return result;
    }
}
```