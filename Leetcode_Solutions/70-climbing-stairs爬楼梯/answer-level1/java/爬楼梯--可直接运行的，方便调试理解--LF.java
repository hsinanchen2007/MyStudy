```
package ZJM_70_爬楼梯;

public class Main {
    public static void main(String[] args) {
        int num1 = 2;
        int num2 = 3;

        Solution solution = new Solution();
        System.out.println(solution.climbStairs(num1));
        System.out.println(solution.climbStairs(num2));
    }
}

class Solution {
    public int climbStairs(int n) {
        int[] temp = new int[n+1];
        temp[0]=1;
        temp[1]=1;

        for(int i=2;i<n+1;i++){
            temp[i] = temp[i-1]+temp[i-2];
        }

        return temp[n];
    }
}

/**
 * 这一题我一开始先将几项计算出来，得到
 * 每次你可以爬 1 或 2 个台阶
 * 1	1                                       1
 * 2	1-1  2                                  2
 * 3	1-2  1-1-1  2-1                         3
 * 4	1-1-2  1-2-1  2-1-1  2-2  1-1-1-1       5
 * ...
 * 结果看着这个数很眼熟，1，2，3，5，再算出5是8，
 * 这不就是斐波那契数列么。。。
 * 然后就简单了
 *
 * 还有另一种暴力破解的思路
 * 在暴力法中，我们将会把所有可能爬的阶数进行组合，也就是 1 和 2 。
 * 而在每一步中我们都会继续调用 climbStairsclimbStairs 这个函数
 * 模拟爬 1_1 阶和 2_2 阶的情形，并返回两个函数的返回值之和。
 * climbStairs(i,n)=(i + 1, n) + climbStairs(i + 2, n)
 * climbStairs(i,n)=(i+1,n)+climbStairs(i+2,n)
 * 其中 i_i 定义了当前阶数，而 n_n 定义了目标阶数。
 *
 * public class Solution {
 *     public int climbStairs(int n) {
 *         climb_Stairs(0, n);
 *     }
 *     public int climb_Stairs(int i, int n) {
 *         if (i > n) {
 *             return 0;
 *         }
 *         if (i == n) {
 *             return 1;
 *         }
 *         return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
 *     }
 * }
 */

```
