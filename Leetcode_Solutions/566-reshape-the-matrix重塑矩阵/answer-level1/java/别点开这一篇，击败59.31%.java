### 解题思路
一共想了两种方法

方法一：先将nums变成int[]的数组（row=1），然后再根据r*c来填充

方法二：就是下面这个，耗时2ms，尝试了很多遍都没有到1ms

### 代码

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(r*c!= nums.length * nums[0].length) return nums;

        int[][] reshape = new int[r][c];

        int row =0, col =0;
        for(int[] i:nums){
            for(int num:i){
                reshape[row][col++ % c] = num;
                if(col % c == 0)
                    row++;
            }
        }
        return reshape;

    }
}
```