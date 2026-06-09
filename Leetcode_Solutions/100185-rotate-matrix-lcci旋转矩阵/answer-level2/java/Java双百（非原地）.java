### 解题思路
原来的纵坐标=换完之后的纵坐标
原来的横坐标=N-换完之后的纵坐标

原地的话：新的部分×100加到原数组，再清理干净
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        //原来的纵坐标=换完之后的纵坐标
        //原来的横坐标=N-换完之后的纵坐标
        int length = matrix.length;
        int[][] next = new int[length][length];
        for(int i=0;i<length;++i)
        {
            for(int j=0;j<length;++j)
            {
                next[i][j] = matrix[length-1-j][i];
            }
        }
        for(int i=0;i<length;++i)
        {
            for(int j=0;j<length;++j)
            {
                matrix[i][j] = next[i][j];
            }
        }
    }
}
```