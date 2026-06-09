### 解题思路
解决思路是倒着找，找到0元素继续往前找，每一个元素到0元素到距离如果小于自己的值，只要有1个，就可以成功飞跃，请看代码和注释

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        // 数组为空不可以
        if(nums.length==0){
            return false;
        }

        // 起始位置为0不可以
        if(nums[0] == 0 && nums.length == 1){
            return true;
        }
        if(nums[0] == 0 && nums.length > 1){
            return false;
        }

        if(nums.length == 1){
            return true;
        }

        int j = nums.length - 2;
        while(j>=0){
            // 处理0元素
            // 主要是0元素不能移动
            int current_num = nums[j];
            if(current_num == 0){
                // 看是否该0元素与前边所有元素的差都正好是元素的值本身
                int current = j;
                boolean isOverZeroDistance = false;
                while(--j>=0){

                    // 如果距离恰好就是元素值
                    if(current - j < nums[j]){
                        isOverZeroDistance = true;
                        break;
                    }
                }
                if(isOverZeroDistance == false){
                    return false;
                }
            }else{
              j--;
            }
        }

        return true;
    }
}
```