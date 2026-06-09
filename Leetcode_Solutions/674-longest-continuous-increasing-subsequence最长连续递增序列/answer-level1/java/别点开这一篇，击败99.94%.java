### 解题思路
思路很简单，就是记录最长的子数组，遇到非升序的时候，就重新计算，最后选最大的出来。

要注意的是，如果是一直升序的话，例如[1, 2, 3, 4]，你需要在最后再判断一次大小

还有就是数组为空的情况

### 代码

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int ans = 1, temp = 1;
        if(nums.length == 0) return 0;

        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] < nums[i + 1]){
                temp++;
            }else{
                ans = Math.max(temp, ans);
                temp = 1;
            }
        }

        ans = Math.max(temp, ans);
        return ans;
    }
}
```