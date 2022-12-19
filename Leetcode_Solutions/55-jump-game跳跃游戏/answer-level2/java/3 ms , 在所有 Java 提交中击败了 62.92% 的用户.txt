例：                   3   2   1   0   1
数组下标i：             0   1   2   3   4
最多跳跃到坐标i的位置：  0+3 1+2 2+1 3+0 最多到3的位置

```
class Solution {
    public boolean canJump(int[] nums) {
        boolean flag = true;
        int key = 0;
        for(int i=0;i<nums.length;i++){
            if(key<i){  //判断能否到数组i
                flag = false;
                break;
            }
            key=Math.max(key,i+nums[i]);//取得目前最大跳跃位置
        }
        return flag;
    }
}
```
