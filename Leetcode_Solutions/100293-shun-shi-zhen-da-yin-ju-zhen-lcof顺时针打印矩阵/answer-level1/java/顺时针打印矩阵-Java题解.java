### 解题思路
设定上、下、左、右四个边界，每遍历完一个边，将其中的元素存入输出数组，而这一边就往中间靠。重复此操作直到边界之间重合或越界。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length == 0) return new int[0];
        int l = 0,r = matrix[0].length - 1,t = 0,b = matrix.length - 1,x = 0; 
        int[] res = new int[(r + 1) * (b + 1)];
        while(true){
            for(int i = l;i <= r;i++) res[x++] = matrix[t][i];
            if(++t > b) break;

            for(int i = t;i <= b;i++) res[x++] = matrix[i][r];
            if(--r < l) break;

            for(int i = r;i >= l;i--) res[x++] = matrix[b][i];
            if(--b < t) break;

            for(int i = b;i >= t;i--) res[x++] = matrix[i][l];
            if(++l > r) break;

        }
        return res;

    }
}
```