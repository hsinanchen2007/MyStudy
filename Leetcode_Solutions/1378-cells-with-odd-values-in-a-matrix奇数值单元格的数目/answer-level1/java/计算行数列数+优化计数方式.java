常规想法是计算行列出现次数，但是最终只用考虑这一行出现是奇数还是偶数，所以只用0，1保存可以节省%2的时间
![image.png](https://pic.leetcode-cn.com/a1f56d81c38cae391c6be624b25d967c6725b6fa9929a539341072c6bab314ca-image.png)
class Solution {
        public int oddCells(int n, int m, int[][] indices) {
            /**
             * 80%,感觉是set判断是否在里面然后删除操作太费时间了尝试用数组代替
             *
             */
            /*version1
            Set<Integer> row = new HashSet<>();
            Set<Integer> col = new HashSet<>();
            int i = 0, j = 0, x = 0, y = 0;
            for (; i < indices.length; i++) {
                if (!row.contains(indices[i][0]))
                    row.add(indices[i][0]);
                else row.remove(indices[i][0]);
                if (!col.contains(indices[i][1]))
                    col.add(indices[i][1]);
                else col.remove(indices[i][1]);
            }
            x = row.size();
            y = col.size();
            return x * m + y * n - 2 * x * y;
            versin1
             */
            /**
             * versin2 双100
             */
            int[] row = new int[51];
            int[] col = new int[51];
            int i = 0, j = 0, x = 0, y = 0;
            for (; i < indices.length; i++) {
                row[indices[i][0]] ^= 1; //0变成1，1变成0
                col[indices[i][1]] ^= 1;
            }
            for (i = 0; i < n; i++)
                x += row[i];
            for (i = 0; i < m; i++)
                y += col[i];
            //return的这个公式可以画画图想想
            return x * m + y * n - 2 * x * y;
        }


