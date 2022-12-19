### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> list = new ArrayList();
        int i = 0, j = 0;
        while (i < A.length && j < B.length) {
            int a0 = A[i][0];
            int a1 = A[i][1];
            int b0 = B[j][0];
            int b1 = B[j][1];
            int maxStart = Math.max(a0,b0);
            int minEnd = Math.min(a1,b1);
            if (minEnd>=maxStart){
                list.add(new int[]{maxStart, minEnd});
            }
            if (a1<b1){
                i++;
            }else {
                j++;
            }
        }
        int[][] result = new int[list.size()][2];
        for (int x = 0; x < list.size(); x++) {
            result[x] = list.get(x);
        }
        return result;
    }
}
```