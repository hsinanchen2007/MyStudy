### 解题思路
![Capture.PNG](https://pic.leetcode-cn.com/5b374cd09717e5d8a29ea0b505d1bb338a79067586fcb602a512bb15a8fa20ea-Capture.PNG)

第一想法是官方题解的回溯方法，结果很不幸的超时了，结果仔细一想这题其实很简单，从最后一个元素向前遍历，如果该点能够到达最后一个点，那么该点的数值应该大于等于这个点到最后一个点的距离。

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int j=nums.length-1;
        for(int i =nums.length-2;i>=0;i--){
            if(nums[i]>=j-i){
                j=i;
            }
        }
        return j==0;
    }
}
```