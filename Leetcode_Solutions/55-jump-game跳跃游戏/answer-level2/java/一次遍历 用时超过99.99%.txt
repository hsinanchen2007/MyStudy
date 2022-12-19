### 解题思路
1.数组无0,则直接通过
2.从后往前遍历,数组有0,用k记录其下标,直到找到能跳跃该位置的值后,将k设置为-1(注意:必须要先把最后一个值为0的位置跳过,才能更新k的值,如果k的前面还有0,但k还未跳过,则不更新k的值)
### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1) return true;
        int k =-1;
        for(int i=nums.length-1;i>=0;i--){
            if(nums[i]>k-i) k=-1;
            if(nums[i]==0&&i!=nums.length-1&&k==-1){
                k=i;
            }
        }
        return k==-1?true:false;

    }
}
```