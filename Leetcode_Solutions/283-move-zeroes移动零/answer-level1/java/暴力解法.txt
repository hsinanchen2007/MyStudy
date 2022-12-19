### 解题思路
第一步：找到第一个0值
第二步：找到下一个非0值, 与当前节点交换

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        //暴力法 - 遍历数组交换
        if (nums.length < 2) {
            return;
        }

        //两次循环--交换
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0 ) {//退出循环
                continue;
            } else {//当前i为0 -- 找到j中第一个不为0的数字 交换
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] != 0) {//交换
                        int temp = nums[i];
                        nums[i]  = nums[j];
                        nums[j]  = temp;
                        break;
                    }
                }
            }
        }

    }
}
```