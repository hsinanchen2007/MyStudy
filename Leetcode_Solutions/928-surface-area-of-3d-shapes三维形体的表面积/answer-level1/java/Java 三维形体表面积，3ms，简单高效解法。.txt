
![image.png](https://pic.leetcode-cn.com/b09ed3e6248f6d16405d63dc288af201d696862c1bef7bb66ba975f3d79ca0d6-image.png)

### 解题思路
1.把第一行抽出来减少一次循环判断的次数，提高执行效率。
2.第一行计算当前位置和与其同行前一个位置的立方体相互接触面的个数。
3.第一列计算当前位置和与其同列前一个位置的立方体相互接触面的个数。
4.其它位置既要计算当前位置的立方体相互接触面的个数，还要计算与同一行，同一列前一个位置的立方体相互接触面的个数。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int sum = grid[0][0];                           //立方体个数
        int inner = grid[0][0] == 0? 0 : grid[0][0]-1;  //所有立方体相互接触面的个数
        int cur = 0;                                      //当前立方体数
        for(int i=1; i<grid[0].length; i++){    //第一行
            cur = grid[0][i];
            if(cur != 0){
                sum += cur;
                inner += cur-1 + Math.min(cur, grid[0][i-1]); 
            }
        }
        for(int i=1; i<grid.length; i++){       //第一行以后
            for(int j=0; j<grid[i].length; j++){
                cur = grid[i][j];
                if(cur != 0){
                    sum += cur;
                    if(j == 0){                     //第一列
                        inner += cur-1 + Math.min(cur, grid[i-1][j]); 
                    }else{                          //第一列以后
                        inner += cur-1 + Math.min(cur, grid[i-1][j]) + Math.min(cur, grid[i][j-1]);
                    }
                }
            }
        }
        return (sum*6) - (inner*2);
    }
}
```