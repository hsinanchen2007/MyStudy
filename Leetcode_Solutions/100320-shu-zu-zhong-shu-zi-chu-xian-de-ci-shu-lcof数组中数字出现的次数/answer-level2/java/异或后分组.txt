### 解题思路
1.先求取所有数字的异或值
2.用异或值上最后一位1 划分两个集合，两个不同的数分别落于两边，相同的数必落于同一个集合，该问题可以简化为 一个集合只有一个数不同，其它两两相同
3.对两个集合 分别做所有数异或即可得解

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        int xor = 0;
        int[] res = new int[2];
        for (int i=0;i<nums.length;i++) {
            xor ^= nums[i];
        }
        // 已异或值上某一位1 划分两个集合，两个不同的数分别落于两边
        int lastOneMask = leastOneBit(xor);
        for (int i=0;i<nums.length;i++) {
            if ((lastOneMask&nums[i]) > 0) {
                res[0] ^= nums[i];
            } else {
                res[1] ^= nums[i];
            }
        }
        return res;
    }
    // 求数字最后一个1的掩码
    public static int leastOneBit(int n) {
        return n & (~n)+1;
    }
}
```
![image.png](https://pic.leetcode-cn.com/c8094a32c188a68c4aec36a3f7ea422fe209b09c8d826f47b9a27973062904fe-image.png)
