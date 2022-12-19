![image.png](https://pic.leetcode-cn.com/4ef823ee5703ee9a144274bf6d6f4e6e791c40d4d24605e43b1250bb478f16f3-image.png)
1️⃣首先遍历二维数组的第一行,从二维数组中的第一个数开始,找出第一行中的最小数值,同时利用一个变量记录当前数字所在的列;
2️⃣然后比较该数值是否是当前列中最大的数字,如果是,则将该数字加入到结果中,否则开始遍历第二行,直到遍历完所有的行.
3️⃣最后返回结果.
具体过程见如下代码.

```
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return new ArrayList<>();
        }
        int m = matrix.length;
        int n = matrix[0].length;
        
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int tmp = Integer.MAX_VALUE;
            // 找到同一行中最小的值
            int p = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < tmp) {
                    tmp = matrix[i][j];
                    p = j;
                }
            }
            int tmpMax = tmp;
            // 比较当前值是否是当前列的最大值
            for (int k = 0; k < m; ++k) {
                if (matrix[k][p] > tmp) {
                    tmpMax = matrix[k][p];
                    break;
                }
            }
            if (tmp == tmpMax) {
                res.add(tmp);
            }
        }
        
        return res;
    }
}
```


