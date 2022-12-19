设数组大小为 m 行，n 列。
下面有两种算法，为保持代码一致性，我将其抽象为 3 个方法，其中只改变 `search()` 方法的实现：
 1. `search1()` 实际上是遍历整个 2 维数组，时间复杂度毫无疑问是 `O(m * n)`，用时 21ms；
 2. `search2()` 与题解中大多数人的实现一样，通过二分查找来确定第一行元素是否在之后的每一行中出现，如果其中一行没有该元素，则跳过整个元素。由于有三重循环，则时间复杂度为 `O(m * n * log(n))`，用时 2ms。

我的想法是，虽然第 2 种方法在用时上比第 1 种方法快，但是其时间复杂度并不低，只不过测试用例没覆盖每一行元素大量重复的情况。如果有类似:
[[1, 2, ..., 100],
 [1, 2, ..., 100],
 [1, 2, ..., 100],
 ...
 [1, 2, ..., 100],
 [101, 102, ..., 200]]
这样，前面每一行元素都相同，但是最后一行元素完全不同的情况，则时间复杂度 `O(m * n * log(n))` 中间的 n 便没有办法消除，也就不会使得时间复杂度降低为 `O(m * log(n))`，这种情况下，二分查找反而会比遍历整个数组的方法慢。

如果有不同想法的朋友，欢迎讨论、指正，感谢！

``` Java
class Solution {
    
    Map<Integer, Integer> map = new HashMap<>();

    public int smallestCommonElement(int[][] mat) {
        if (mat.length < 2 || mat[0].length < 1) {
            return -1;
        }

        init(mat);

        search2(mat);

        return getResult(mat);
    }

    // init O(n)
    private void init(int[][] mat) {
        for (int c = 0; c < mat[0].length; c++) {
            add(mat[0][c]);
        }
    }

    private void add(int i) {
        if (map.containsKey(i)) {
            int time = map.get(i);
            map.put(i, time + 1);
        } else {
            map.put(i, 1);
        }
    }

    // O(m * n)
    private void search1(int[][] mat) {
        for (int r = 1; r < mat.length; r++) {
            for (int c = 0; c < mat[0].length; c++) {
                int cur = mat[r][c];
                if (map.containsKey(cur)) {
                    int time = map.get(cur);
                    map.put(cur, time + 1);
                }
            }
        }
    }

    // O(m * n * log(n))
    private void search2(int[][] mat) {
        Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();

        while (it.hasNext()) {
            Map.Entry<Integer, Integer> item = it.next();
            int key = item.getKey();

            for (int r = 1; r < mat.length; r++) {
                boolean isFind = binarySearch(mat[r], key);
                if (isFind) {
                    add(key);
                } else {
                    break;
                }
            }
        }
    }

    // O(n)
    private int getResult(int[][] mat) {
        Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Integer, Integer> entry = it.next();
            if (entry.getValue() == mat.length) {
                return entry.getKey();
            }
        }
        return -1;
    }

    // O(log(n))
    private boolean binarySearch(int[] row, int target) {
        int left = 0;
        int right = row.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cur = row[mid];
            if (cur < target) {
                left = mid + 1;
            } else if (cur > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
```