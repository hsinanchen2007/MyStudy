### 解题思路
自顶向下的贪心算法

核心思路找到目标位置的上一位到达后所剩余的最大步数，如果该位置的上一位剩余步数大于0则，目标位置可达，如果在某一位置步数消耗殆尽，则不可达。

目标索引的最大剩余步数：MAX（上一位置剩余步数-1，当前位置可获得步数）
lastStep = Math.max(step,nums[index]);

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int lastIndex = nums.length - 1;
        int lastStep = nums[0];
        if(lastIndex==0)
            return true;
        for(int index = 1;index<lastIndex;index++){
            int step = lastStep-1;
            if(step>=0){
                 lastStep = Math.max(step,nums[index]);
            }else
                return false;
           
        }

        return lastStep>0;

    // return canculate(nums,0,nums.length-1);
    }
    
    // public boolean canculate(int[] nums,int start,int count){
    //     boolean can = false;
    //     int step = nums[start];
    //     if(step>=count){
    //         return true;
    //     }

    //     for(int i = 1;i<=step;i++){
    //         if (canculate(nums,start+i,count-i)){
    //             return true;

    //         }
    //     }
    //     return can;
    // }
}
```