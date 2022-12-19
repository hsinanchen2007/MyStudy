### 解题可能有点取巧
1.从左往右便利，没有0值，说明可以跳过
2.碰到0值，再往前遍历判断是否可以跳过这个0值，如果不能跳过0值，就直接返回 false
### 代码

```java
class Solution {
    // public boolean canJump(int[] nums) {
    //     int max = 0;
    //     for (int i = 0;i<nums.length;i++){
    //         if(max<i) return false;
    //         max = Math.max(max,nums[i]+i);
    //     }
    //     return true;
    // }

    static public boolean canJump(int[] nums){
        if (nums.length==1&&nums[0]==0) return true;
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i]==0){
                int j = i-1;
                while(j>=0 && nums[j]+j<=i ){
                    j--;
                }
                if (j<0) return false;
            }
        }
        return true;
    }
}
```