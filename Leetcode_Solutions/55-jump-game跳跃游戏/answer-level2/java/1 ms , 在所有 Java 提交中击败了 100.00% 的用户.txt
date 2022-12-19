### 解题思路

如果数组是正数就可以一直往后跳。

因此解题核心在于判断数组中每个0能否越过去。


### 代码

```java
class Solution {

    public boolean canJump(int[] nums) {
        int target = nums.length - 1;
        int index = 0;
        boolean canJump_flag;
        while (index < target){
            canJump_flag = false;
            if (nums[index] == 0){
                for (int i = 0; i < index; i++){
                    if (index - i < nums[i]){
                        canJump_flag = true;//只要前面有一个数字能跳过0即可
                        break;
                    }
                }
                if (!canJump_flag){
                    return false;//跳不过0则直接返回结果
                }
            }
            index++;
        }
        return true;
    }

}
```