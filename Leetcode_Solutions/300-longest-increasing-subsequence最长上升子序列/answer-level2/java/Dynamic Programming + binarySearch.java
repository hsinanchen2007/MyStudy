### Dynamic Programming
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        //special
        if(nums.length <= 1) return nums.length;
        //dp[i] represents the case that end with each nums[i] 
        int[] dp = new int[nums.length];
        int len = 0;
        //base case
        dp[0] = 1;
        
        for(int i = 1; i < nums.length; i++) {
            int temp = 1;
            //find one case that
            //as long as possible under the end element min than current element
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) 
                    temp = Math.max(temp, dp[j] + 1);
            }
            //haven been found
            dp[i] = temp;
            //update current length
            len = Math.max(len, dp[i]);
        }

        return len;
    }
}
```
### binarySearch
Optimization algorithm :
we use a method that :
find forward cases, to find the as long as possible under the element at the end less than current.
now we make a Array that has as small as possible element each length case.
use binarySearch to find the best case. 
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        //special
        if(nums.length <= 1) return nums.length; 
        //dp[i] :
        //currently the small ending element that length is i + 1 
        int[] dp = new int[nums.length];

        //base case
        int len = 1;
        dp[0] = nums[0];

        for(int i = 1; i < nums.length; i++) {
            int j = 0, k = len;
            //binarySearch
            while(j < k) {
                int m = j + (k - j) / 2;
                if(dp[m] < nums[i]) j = m + 1;
                else k = m;
            }
            dp[k] = nums[i];
            if(k == len) len++;
        }


        return len;
    }
}
```
