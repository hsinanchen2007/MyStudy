### 解题思路
该方法步骤如下：
1.检测数组里是否包含1，如果不包含，则返回缺失的“1”；
2.将数组内所有小于1，大于nums长度的都转为1；
3.如果1存在，就将nums[1-1] 设定为负数；如果2存在，就将nums[2-2]设定为负数；这样再度循环的时候，nums[i]如果是正数的话，最终缺少的数字就是(i+1);如果没有正数，缺少的数字便是nums.length + 1。

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int length = nums.length;

        // 首先查看是否存在1
        boolean isOneExisted = false;
        for (int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                isOneExisted = true;
                break;
            }
        }
        if (!isOneExisted){
            return 1;
        }

        // 将数组内所有小于1，大于nums长度的都转为1
        for (int i = 0; i < length; i++){
            if (nums[i] < 1 || nums[i] > length){
                nums[i] = 1;
            }
        }

        // 如果1存在，就将nums[0] 设定为负数；
        // 如果2存在，就将nums[1] 设定为负数；
        // 这样再度循环的时候，nums[i]如果为正数的话，最终缺少的数字就是(i+1)
        // 如果没有正数，缺少的数字便是nums.length + 1
        for (int i = 0; i < length; i++){
            int val = Math.abs(nums[i]);
            if(nums[val-1] > 0){
                nums[val-1] *= -1;
            }
        }

        for (int i = 0; i < length; i++){
            if (nums[i] > 0){
                return i + 1;
            }
        }
        return length + 1;
    }
}
```