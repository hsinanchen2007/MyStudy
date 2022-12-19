### 解题思路
不知道官方答案的思路为啥这么繁琐， 顺序遍历就完事了。
从第一个点开始，找到它能够着的最远点，用一个变量maxPos来记录这个点的坐标。
后面的点如果能够着更远的点，就更新maxPos。
当发现maxPos大于等于数组的最后一个元素坐标时，就表示能跳出数组。

只有一种情况会导致失败，就是遍历的过程中，发现当前的坐标大于maxPos，
这就表示，当前这个点是无法通过之前的点跳跃而达到的。

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 0){
            return false;
        }
        int maxPos = 0;
        for(int i=0; i<nums.length; i++){
            if (i > maxPos){
                return false;
            }
            maxPos = Math.max(i + nums[i], maxPos);
            if (maxPos >= nums.length - 1){
                return true;
            }
        }
        return false;
    }
}
```