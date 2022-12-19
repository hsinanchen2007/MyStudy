### 解题思路
1. 对数组排序
2. n 行最大为 2*n, 根据输入数组动态调整

### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int count = 2 * n;
        Arrays.sort(reservedSeats, Comparator.comparingInt(a -> a[0]));
        Set<Integer> col;

        int i = 0, len = reservedSeats.length;
        while (i < len) {
            int row = reservedSeats[i][0];
            col = new HashSet<>();
            do {
                col.add(reservedSeats[i][1]);
            } while ((++i) < len && reservedSeats[i][0] == row);
            boolean flagA = false, flagB = false;
            if (col.contains(2) || col.contains(3) || col.contains(4) || col.contains(5)) {
                count--;
                flagA = true;
            }
            if (col.contains(8) || col.contains(9) || col.contains(6) || col.contains(7)) {
                count--;
                flagB = true;
            }
            if (flagA && flagB && !col.contains(4) && !col.contains(5) && !col.contains(6) && !col.contains(7)) {
                count++;
            }
        }
        return count;
    }
}
```