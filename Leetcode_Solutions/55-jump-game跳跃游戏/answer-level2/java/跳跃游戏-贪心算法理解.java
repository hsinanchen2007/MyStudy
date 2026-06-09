### 解题思路
1. lastPos初始化为数组的末尾位置，依次遍历直至位置0（如果能够到达），维护一个能够到达末尾位置的最左的位置
2. 在每个位置i的判断：如果i+nums[i]>=lastPos，那么可以确定位置i必然能够到达lastPos位置，又已知lastPos是维护的能够到达末尾位置的位置，那么可以推导出i必然能够到达末尾位置

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if(nums==null||nums.length<1){
            return false;
        }
        
        int lastPos=nums.length-1;
        
        for(int i=nums.length-1;i>=0;i--){
            if(i+nums[i]>=lastPos){
                lastPos=i;
            }
        }
        return lastPos==0;
    }
}
```