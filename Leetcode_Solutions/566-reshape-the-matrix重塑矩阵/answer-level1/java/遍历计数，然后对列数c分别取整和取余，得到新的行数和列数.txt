按行遍历原始矩阵，然后用count计数，c是新的列数，那么count/c 就是新的行，count%c就是新的列。
```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int len1 = nums.length;
        int len2 = nums[0].length;
        if(len1 * len2 != r * c) return nums;
        
        int[][] res = new int [r][c];
        int count = 0;
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                res[count / c][count % c] = nums[i][j];
                count++;
            }
        }
        return res;
    }
}
```
例如nums = [[1,2,3], [4,5,6]], r = 3, c = 2;

res[0/2][0%2] = res[0][0] = nums[0][0]

res[1/2][1%2] = res[0][1] = nums[0][1]

res[2/2][2%2] = res[1][0] = nums[0][2]

res[3/2][3%2] = res[1][1] = nums[1][0]

res[4/2][4%2] = res[2][0] = nums[1][1]

res[5/2][5%2] = res[2][1] = nums[1][2]

结果res = [[1,2], [3,4], [5,6]]
