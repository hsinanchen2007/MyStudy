### 解题思路
数组从后向前遍历求解

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        
        boolean flag = true;//判断上次跳跃是否可以到达，可以为true,否则为false
        int len = 0;//用于记录已经连续多少次不可跳达最后一次可跳达的次数
        if(nums.length<=1) return true;//数组为长度小于等于1时直接返回true

        for (int i = nums.length-2; i >=0; i--) {//从数组倒数第二个向前遍历
            if(flag&&nums[i]>=1)continue;//上次跳跃可达，且这次可跳步数大于等于1时，继续下次遍历
            if (flag && nums[i] == 0) {//相反，上次可跳达，此次步长为0时
                flag=false;//置为不可达
                len++;//记录连续多少次不可达
            } else if (!flag && nums[i] > len) {//
                flag=true;
                len = 0;
            } else if (!flag && nums[i] <= len) {
                len++;
            }
        }
        return flag;
    }
}
```