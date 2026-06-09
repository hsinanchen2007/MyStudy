### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int n = nums.length;
        int[] dp = new int[n+1];
        dp[1] = nums[0];
        int len = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] > dp[len]){
                dp[++len] = nums[i];
            }
            else if(nums[i] < dp[len]){
                int l = 1, r = len;
                boolean flag = false;
                //重点，因为是左闭右闭区间，所以l<r；
                while(l < r){
                    int mid = l + (r-l)/2;
//可能mid就是要替换的数字
                    if(nums[i] < dp[mid]){
                        r = mid;
                    }
//因为num大于mid的话，一定是替换更后面的数字
                    else if(nums[i] > dp[mid]){
                        l = mid+1;
                    }else if (nums[i] == dp[mid]){
                        flag = true;
                        break;
                    }
                }
                dp[l] = flag?dp[l]:nums[i];
            }
        }
        System.out.println(len);
        return len;
    }
}
```