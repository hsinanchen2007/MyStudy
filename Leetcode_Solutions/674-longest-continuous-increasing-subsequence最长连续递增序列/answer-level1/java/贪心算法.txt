用一个变量ans保存到当前位置的递增连续子序列的长度，并把最大长度存起来
```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int res = 1;
        int ans = 1;
        int n = nums.length;
        if(n == 0){
            return 0;
        }
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                ans++;
            }else{
                ans = 1;
            }
            if(ans > res){
                res = ans;
            }
        }
        return res;
    }
}
```
奇怪的是，我这个时间复杂度为O(N),空间复杂度为O(1),但是不知道为什么内存消耗只超过了5%的人