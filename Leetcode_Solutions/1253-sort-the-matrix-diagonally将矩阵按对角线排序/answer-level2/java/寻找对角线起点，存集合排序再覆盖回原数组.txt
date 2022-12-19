### 解题思路
暴力遍历矩阵，找到对角线起点，将整条线上的数字加入集合并排序，最后将排序好的集合一一覆盖回该对角线上。

### 代码

```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        
        int m = mat.length;
        int n = mat[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) continue;   // 不是对角线的起点，跳过。

                int x = i;
                int y = j;

                List<Integer> list = new ArrayList<>();    //将对角线上的数加入集合中并排序
                while (x < m && y < n) list.add(mat[x++][y++]);
                Collections.sort(list);

                x = i;
                y = j;

                int index = 0;                              //将排序好的集合再重新覆盖原对角线上的位置
                while (x < m && y < n)  mat[x++][y++] = list.get(index++);
            }
        }

        return mat;
    }
}
```

执行用时 :9 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :39.4 MB, 在所有 Java 提交中击败了100.00%的用户