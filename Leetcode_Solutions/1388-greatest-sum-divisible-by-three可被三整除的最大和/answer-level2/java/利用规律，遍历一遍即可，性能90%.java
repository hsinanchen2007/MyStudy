### 解题思路
整体思路
1、如果要让总和可以被3整除，那么需要减去余数相同的值，这个值可以是一个数，也可以是多个数的和
2、为了要让总和最大，那么应该减去尽量小的值
因此，我的第一版是先把数据排序了，然后从小到大的找合适的值，性能不高。后来改了一版如下。

对于总和，算法需要处理2种情况：余数为1和余数为2的时候（能整除就不说了）
如果我们要减去一个余数为1的值，我们又有两种方案：
方案1：找1个余数为1的最小的值
方案2：找2个余数为2的最小的值求和
然后在这2个值之间看谁最小，就扣除谁。

同理，可分析出余数为2的两种方案：
方案1：找1个余数为2的最小的值
方案2：找2个余数为1的最小的值求和
然后在这2个值之间看谁最小，就扣除谁。

因此，我设计了一个2x2的数组，第一行存余数为1的最小的两个值，第二行存余数为2的最小的两个值，也就是代码中的matrix

然后通过一次遍历，填好这个2x2数组

按照示例1的话，结果就是：
![image.png](https://pic.leetcode-cn.com/8708a949cddb62d38f4dc38842100ea44b2794aa83b516349b8866eca2d368d9-image.png)

最后进行分析：
如果总和的余数为1：
1、取matrix[0][0])（最小的余数为1的值）
2、取matrix[1][0]+matrix[1][1]的和（两个余数为2的数凑出一个余数为1的值）
3、然后看他们谁小，就减去谁
同理处理余数为2的情况

按照示例1的数据来看，就是
1、由于总和为23，余数为2
2、那么方案1，就是在矩阵中找到5
3、然后根据方案2，去尝试找2个余数为1的数才凑，结果发现只有1个有效数据，因此不考虑方案2
4、由于方案2不可行，那么直接返回方案1，23减去5得到18

### 代码

```java
public class Solution {
    private static final int LOW1 = 0;
    private static final int LOW2 = 1;

    public int maxSumDivThree(int[] nums) {
        int[][] matrix = new int[2][2];
        Arrays.fill(matrix[0], Integer.MAX_VALUE);
        Arrays.fill(matrix[1], Integer.MAX_VALUE);

        int total = 0;
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            if (nums[i] % 3 == 0) {
                continue;
            } else {
                if (matrix[nums[i] % 3 - 1][LOW1] > nums[i]) {
                    matrix[nums[i] % 3 - 1][LOW2] = matrix[nums[i] % 3 - 1][LOW1];
                    matrix[nums[i] % 3 - 1][LOW1] = nums[i];
                } else if (matrix[nums[i] % 3 - 1][LOW2] > nums[i]) {
                    matrix[nums[i] % 3 - 1][LOW2] = nums[i];
                }
            }
        }

        if (total % 3 == 0) {
            return total;
        } else if (total % 3 == 1) {
            int plan1 = matrix[0][0] == Integer.MAX_VALUE ? Integer.MAX_VALUE : matrix[0][0];
            int plan2 = matrix[1][1] == Integer.MAX_VALUE ? Integer.MAX_VALUE : matrix[1][0] + matrix[1][1];

            return analyzeDelta(total, plan1, plan2);
        } else {
            int plan1 = matrix[1][0] == Integer.MAX_VALUE ? Integer.MAX_VALUE : matrix[1][0];
            int plan2 = matrix[0][1] == Integer.MAX_VALUE ? Integer.MAX_VALUE : matrix[0][0] + matrix[0][1];

            return analyzeDelta(total, plan1, plan2);
        }
    }

    private int analyzeDelta(int total, int plan1, int plan2) {
        if (plan1 == Integer.MAX_VALUE && plan2 == Integer.MAX_VALUE) {
            return 0;
        } else {
            return total - Math.min(plan1, plan2);
        }
    }
}
```