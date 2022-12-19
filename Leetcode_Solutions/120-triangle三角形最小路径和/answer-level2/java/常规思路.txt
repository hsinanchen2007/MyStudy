### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int[] ret = new int[triangle.size()];

        for (List<Integer> row: triangle) {
            int last = row.size()-1;
            final int first = 0;

            for (int i = last; i>=first; --i) {
                if (i == first)
                    ret[i] = row.get(i) + ret[first];
                else if (i == last)
                    ret[i] = row.get(last) + ret[i-1];
                else
                    ret[i] = row.get(i) + Math.min(ret[i-1], ret[i]);
            }
        }

        int min = ret[0];
        for (int n: ret)
            min = Math.min(n ,min);
        return min;
    }
}
```