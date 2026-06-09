核心思想就是判断每个字符串中，相同索引位置上的字符是否是非降序排列的，如果不是，那就把计数器加1。

```
    public int minDeletionSize(String[] A) {
        int count = 0;
        for (int j = 0; j < A[0].length(); j++) {
            char lst = A[0].charAt(j);
            for (int i = 0; i < A.length; i++) {
                if (lst > A[i].charAt(j)) {
                    count++;
                    break;
                }
                lst = A[i].charAt(j);
            }
        }
        return count;
    }
```
