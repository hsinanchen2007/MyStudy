思路比较简单：
1. 判断给定的数组能否转为新的数组，主要看元素个数，个数相同则可转
2. 如果可转，建立一个新的数组`int[][] res = new int[r][c]`
3. 用指针`i j`去遍历原数组中的元素，用指针`k l` 去遍历`res`数组
4. 注意换行条件 `l==c`，行`+1`，列`=0`

（第一次写题解写得不好还请指出呀 谢谢）

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int total = nums.length * nums[0].length;
        if (r * c != total) return nums;  //如果不能reshape则返回原数组
        int[][] res = new int[r][c];
        int k = 0, l = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[i].length; j++) {
                res[k][l] = nums[i][j];
                l++;
                if (l == c) {
                    k++;
                    l = 0; //数组换行
                }
            }
        }

        return res;
        
    }
}
```
