### 解题思路
本题也并不难，理解题目意思会非常简便，什么时候返回原数组，只要我们无法reshape这个矩阵，即原来的矩阵所有数的数量无法刚好分配到新的矩阵中且无空余，只要不满足这点，我们就返回原数组，因此只要原矩阵的行数*列数不等于reshape后的值则返回原数组，如果满足，首先把二维数组的值全部取出到一维数组中去，然后依次遍历取出即可。

### 代码

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(nums.length*nums[0].length!=r*c) {
            return nums;
        }
        int count = 0;
        int[] brr = new int[r*c];
        for(int i = 0;i<nums.length;i++) {
            for(int j = 0;j<nums[i].length;j++) {
                brr[count++] = nums[i][j];
            }
        }
        nums = new int[r][c];
        count = 0;
        for(int i = 0;i<r;i++) {
            for(int j = 0;j<nums[i].length;j++) {
                nums[i][j] = brr[count++];
            }
        }
        return nums;
        
    }
}
```