### 解题思路
动态规划分析思路：
1）寻找子问题：即 子序列，起始位置为0，结束位置为j的子数组。变量为子数组的结束位置
2）状态：即等差序列的个数
3）状态转移方程：考虑dp[j]和dp[j-1]的关系：都从0开始的话，0到j-1序列的等差序列假设为A，则0到j的算法为：
--若A[j]和前面两个数无法形成等差，则dp[j]=dp[j-1];
--若A[j]能够和前面两个数形成等差且等差为delta，则要从后往前遍历看有多少个和delta相等的等差，其个数即为由于A[j]的加入而新增的等差子序列，设为num，则公式为dp[j]=dp[j-1]+num
备注：一开始的思考是i和j一头一尾的两个位置锁定一个子序列，需要一个dp[i][j]的二维数组；实际不需要，因为如上分析，0到j-1的子序列求解出来了，只要看把j位置的数加上后新增了多少等差序列即可算出j位置结尾的数目了，而任意i和j构成的子序列所包含的等差序列个数已经包含在了0到j的计算统计之内
时间复杂度：O(n*n)

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A.length == 0) return 0;
        int n = A.length;
        int dp[]= new int[n];
        for (int j = 1; j < n; j++) {
            if(j < 2) {
                dp[j] = 0;
                continue;
            }

            if(A[j]-A[j-1] == A[j-1]-A[j-2]) {
                int delta = A[j]-A[j-1];
                int num = 1;
                for (int k = j-2; k-1 >= 0; k--) {
                    if(A[k]-A[k-1] == delta) {
                        num++;
                    } else {
                        break;
                    }
                }
                dp[j] = dp[j-1] + num;
            } else {
                dp[j] = dp[j-1];
            }

            //System.out.println("dp["+j+"]: " + dp[j]);
        }

        return dp[n-1];
    }
}
```