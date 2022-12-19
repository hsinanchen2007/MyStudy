### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if(ops==null||ops.length==0){
            return m*n;
        }
        int min_i=Integer.MAX_VALUE,min_j=Integer.MAX_VALUE;
        for(int i=0;i<ops.length;i++){
            if(min_i>ops[i][0]) min_i=ops[i][0];
            if(min_j>ops[i][1]) min_j=ops[i][1];
        }
        return min_i*min_j;
    }
}
```