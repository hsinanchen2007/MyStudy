### 解题思路
使用动态规划来解，超出内存限制...
### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        return (n % 4 != 0);
}
    
//         public boolean canWinNim(int n) {
//         if(n < 4){
//             return true;
//         }
//         int[] nums = new int[n+1];
//         nums[1] = 1;
//         nums[2] = 1;
//         nums[3] = 1;
//         for(int i = 4;i<=n;i++){
//             nums[i] = nums[i-1] + nums[i-2] + nums[i-3] + 3;
//         }
//         if(nums[n] % 2 == 0){
//             return false;
//         }else{
//             return true;
//         }
// }
}
```