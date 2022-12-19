### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {

        int n = nums.length;
        if(n < 2) return false;
        int sum = 0;
        for(int i = 0; i < n-1; i++) {
            sum += nums[i];
            for(int j = i+1; j< n; j++) {
                sum += nums[j];              
                // 讨论等式成立的情况
                if((sum == 0) || (sum != 0 && k !=0 && sum % k == 0)) {
                    return true;
                } 
            }
            sum = 0;
        }


        return false;

    }
}
```