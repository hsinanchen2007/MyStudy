### 解题思路
注释的部分是暴力思路，记录能走到的节点，定义为true，为当前的boolean||起跳点的boolean
写的部分是抄的答案，记录每次能走到的最大范围，当最大范围小于遍历的index时，则返回false，否则就是true。

### 代码

```java
class Solution {
//     public boolean canJump(int[] nums) {

//         boolean[] dp=new boolean[nums.length];
//         dp[0]=true;
//         for (int i=0;i<nums.length;i++)
//         {
//             for (int j=0;j<=nums[i];j++)
//             {
// //                if (i+)
//                 if ((i+j)>=nums.length)
//                     break;
// //                if ()
//                 dp[i+j]= dp[i]||dp[i+j];
//             }
//         }
//         return dp[nums.length-1];
// //        return false;
//     }
    public boolean canJump(int[] nums) {
        int k=0;
        for(int i=0;i<nums.length;i++)
        {
            if(k<i)
                return false;
            k=Math.max(k,nums[i]+i);
        }
        return true;
    }
}
```