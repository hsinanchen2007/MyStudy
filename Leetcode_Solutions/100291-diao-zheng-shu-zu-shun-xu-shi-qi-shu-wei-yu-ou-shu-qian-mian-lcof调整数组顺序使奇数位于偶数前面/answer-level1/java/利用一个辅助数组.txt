```Java []
class Solution {
    public int[] exchange(int[] nums) {
        int[] ans = new int[nums.length];
        int left = 0, right = nums.length-1;
        for (int n : nums) {
            if (n % 2 != 0) {
                ans[left++] = n;
            }else{
                ans[right--] = n;
            }
        }
        return ans;
    }
}
```
```Python []
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        ans = [0]*len(nums)
        left, right = 0, len(nums)-1
        for num in nums:
            if num % 2 != 0:
                ans[left] = num
                left += 1
    
            else:
                ans[right] = num
                right -= 1
        return ans
```
