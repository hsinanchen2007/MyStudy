### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Scanner;

/**leetcode0461汉明距离
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。

 */
class Solution {
    Solution(){

    }
    public int hammingDistance(int x, int y) {
        int cnt = 0;
        while(x != 0 || y != 0){
            cnt += (x ^ y) & 1;
            x >>= 1;
            y >>= 1;
        }
        return cnt;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.println(solution.hammingDistance(x, y));
        sc.close();
    }
}
```