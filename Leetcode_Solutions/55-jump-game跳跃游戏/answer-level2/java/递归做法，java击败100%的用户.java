### 解题思路
1：从倒数第二位开始，判断每一位是不是0 如果都不是0 则一定是true
2: 如果当前位是0，那么就判断从0的这一位前面，每一位上的值是不是大于位置之差（i-j），如果所有位置上都小于等于差值，那么返回false；如果出现有一位是大于差值的，那就递归判断，能否到达当前位置。

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
         if(nums==null||nums.length==0) return false;
         int end=nums.length-1;
         return canJump_1(nums,end);
    }
    public boolean canJump_1(int[] nums,int end){
        if(end==0) return true;
        for(int i=end-1;i>=0;i--){
            if(nums[i]==0){
                for(int j=i-1;j>=0;j--){
                    if(nums[j]>(i-j)){
                        return canJump_1(nums,j);
                    }
                }
                return false;
            }
        }
        return true;
    }
}
```