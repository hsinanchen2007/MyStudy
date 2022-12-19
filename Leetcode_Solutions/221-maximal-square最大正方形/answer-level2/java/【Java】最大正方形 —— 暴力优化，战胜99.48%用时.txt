虽然暴力的时间复杂度为 $O((nm)^2)$ ，DP的时间复杂度为 $O(nm)$ ，但是在目前的测试数据下，暴力经过一定的优化后甚至能比未优化的DP还要快一些。
![图](https://pic.leetcode-cn.com/acaa0a028c3d9b2e0656b6cd5dd350f139efe8953ad3a4c60faf30f6a5244364-TIM%E6%88%AA%E5%9B%BE20200320233643.png)


优化要点：不再去检测比现在的最大正方形要小的正方形。
具体措施：对矩阵进行遍历时，如果剩余宽度小于已确定的最大宽度，则停止循环；检测正方形时直接从最大宽度加一开始检测。
```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < matrix.length - ans; ++i) {
            for (int j = 0; j < matrix[i].length - ans; ++j) {
                if (matrix[i][j] != '1') {
                    continue;
                }
                int max = Math.min(matrix.length - i,matrix[i].length - j);
                for (int k = ans + 1; k <= max; ++k){
                    boolean flag = true;
                    for (int a = 0; a < k; a++){
                        for (int b = 0; b < k; b++){
                            if (matrix[i + a][j + b] != '1') {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) {
                            break;
                        }
                    }
                    if(!flag) {
                        break;
                    }
                    ans = k;
                }
            }
        }
        return ans*ans;
    }
}
```