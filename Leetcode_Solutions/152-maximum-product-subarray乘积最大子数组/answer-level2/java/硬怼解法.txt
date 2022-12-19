### 解题思路
思路简单，就是设置每个点的最大可用乘积，然后每次遍历都是根据当前点与前一个点的情况讨论，情况很多需要
多试。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        // 和连续递增子序列一样，我用两个数组来存储能与下一个点交互的正负两种情况的最大值
        int[] op = new int[nums.length];
        int[] di = new int[nums.length];
        // 状态转移：
        // 当前数字为正：op[i] = op[i-1] * nums[i] 与  最大值，
        if (nums == null || nums.length == 0) {
            return 0;
        }
        // 这里初始化
        if (nums[0] < 0) {
            op[0] = 0;
            di[0] = nums[0];
        } else if (nums[0] > 0) {
            op[0] = nums[0];
            di[0] = 0;
        } else {
            op[0] = 0;
            di[0] = 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        double maxInt = op[0];
        for (int i=1;i<nums.length;i++) {
            // 第一种大情况，当前点为0,则一切不变
            if (nums[i] == 0) {
                op[i] = 0;
                di[i] = 0;
            }
            // 第二种大情况，当前点为正
            if (nums[i] > 0) {
                // 前面一个点是否为0
                if (nums[i - 1] == 0) {
                    op[i] = nums[i];
                    di[i] = 0;
                } else {
                    if (op[i - 1] == 0) {
                        op[i] = nums[i];
                    } else {
                        op[i] = op[i-1] * nums[i];
                    }
                    if (di[i - 1] != 0) {
                        di[i] = di[i-1] * nums[i];
                    } else {
                        
                    }
                }
            }
            // 第三种大情况，当前点为负
            if (nums[i] < 0) {
                // 前一个点是否为0
                if (nums[i - 1] == 0) {
                    op[i] = 0;
                    di[i] = nums[i];
                } else {
                    
                    if (di[i - 1] == 0) {
                        di[i] = nums[i];
                    } else {
                        op[i] = di[i-1] * nums[i];
                    }

                    if (op[i - 1] != 0) {
                        di[i] = op[i-1] * nums[i];
                    } else {
                        di[i] = nums[i];
                    }
                }
            }
            System.out.println(i+":"+op[i]+":"+di[i]);
            if (op[i] > maxInt) {
                maxInt = op[i];
            }
        }
        return (int)maxInt;
    }
}
```