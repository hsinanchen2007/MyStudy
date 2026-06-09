### 解题思路
此处撰写解题思路
动态规划把nums数组重置为最远跳多远
### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if(i>nums[i-1]) return false;      //跳不过去了直接return了
            nums[i]= (nums[i-1]>(nums[i]+i) ?nums[i-1]:nums[i]+i); //把nums重置
            if(nums[i]>=nums.length-1) return true;   //跳得过去直接return true
        }
        return true;//若长度为1不执行循环直接return true
    }
}


//另一个版本1ms
/*从后往前动态规划
public static boolean canJump(int[] nums) {
        if(nums.length==1) return true;
        if(nums[0]==0) return false;
        int len=0;
        int i=0;
        for ( i = nums.length - 2; i >= 0; i--) {
            if(nums[i]+i>=nums.length-1) {
                nums[i]=i;
                len=i;
                break;
            }
        }
        if(i==-1) return false;
        if(len==0) return true;
        for ( i = len - 1; i >= 0; i--) {
            if(nums[i]+i>=nums[i+1]) nums[i]=i;
            else nums[i]=nums[i+1];
        }
        if(nums[0]==0) return true;
        return false;



    }

*/
```