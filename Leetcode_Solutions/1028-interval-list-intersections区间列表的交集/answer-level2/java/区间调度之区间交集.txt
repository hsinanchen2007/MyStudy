### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> res = new ArrayList<>();
        if (A == null || B == null) {
            return res.toArray(new int[0][]);
        }
        // 定义两个指针遍历两个数组
        int i =0;
        int j =0;
        while (i < A.length && j < B.length) {
            int a1 = A[i][0];
            int a2 = A[i][1];
            int b1 = B[j][0];
            int b2 = B[j][1];
            //1 说明有重合
            if (a1 <= b2 && a2 >= b1) {
                //2 重合区间：前面的最大值 到 后面的最小值
                int start = Math.max(a1, b1);
                int end = Math.min(a2, b2);
                res.add(new int[]{start, end});
            }
            //3 哪个区间大，哪个不动，另一个指针动，看是否能扩大重合区间
            if (a2 > b2) {
                j++;
            } else {
                i++;
            }
        }
        return res.toArray(new int[0][]);
    }
}
```