### 解题思路
a[m][n] = a[m-1][n-1] + a[m-1][n+1]

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> array = new ArrayList<>(numRows);
        if (numRows <= 0) {
            return array;
        }
        // a[m][n] = a[m-1][n-1] + a[m-1][n+1]
        for (int j = 0; j < numRows; j++) {
            List<Integer> row = new ArrayList<>();
            for (int i = 0; i < j + 1; i++) {
                row.add(1);
            }
            if (j > 1) {
                for (int i = 0; i < j + 1; i++) {
                    if (i > 0 && i < j) {
                        row.add(i, array.get(j - 1).get(i - 1) + array.get(j - 1).get(i));
                    }
                }
            }
            array.add(j, row.subList(0, j+1));
        }
        return array;
    }
}
```