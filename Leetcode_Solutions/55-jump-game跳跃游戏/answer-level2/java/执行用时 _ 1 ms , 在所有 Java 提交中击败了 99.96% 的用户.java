### 解题思路
置顶大佬请收下我的膝盖

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        //从倒数第二个位置开始 如果这个位置的值大于space，说明能到你的最近目标
        if(nums.length==1){
            return true;
        }
    //    int[] arr= {2,0,0};
    //    nums = arr;
       int space = 0;
       for(int i=nums.length-1;i>=0;i--){
           //当前 
           if(nums[i]>=space){
               // i 是可达的，继续向前看能否有点可以到i。
               space = 1;
           }else{
               //当前位置到不了目标，向前找吧，距离得加大
               space++;
           }
           if(i==0&&space>1){
               return false;
           }
       }
       return true;
    }

}
```