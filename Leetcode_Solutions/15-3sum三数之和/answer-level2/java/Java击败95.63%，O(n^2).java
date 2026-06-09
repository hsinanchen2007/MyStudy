### 解题思路
这题就是找N次不同target的TwoSum，TwoSum算法能想到用双指针这题就快很多。想不到就只能三重遍历，一般三重遍历的算法都会超出时间限制。
我看精选题解里面对于去重的代码并不简洁，所以分享一下我的解法：思路就是在找到一个三元组后，移动指针的时候跳过与上次相同的数。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // O(nlgn)
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        // O(n^2)
        for(int i = 0; i < nums.length - 2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i], left = i+1, right = nums.length - 1;
            while(left < right){
                int twoSum = nums[left] + nums[right];
                if(twoSum == target){
                    ans.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    // 跳过与相同的数
                    while(left + 1 < nums.length - 1 && nums[left] == nums[left+1]) left++;
                    while(right - 1 > i + 1 && nums[right] == nums[right-1]) right--;
                    // 定位到下一个不相同的数，即使left>right了也没事
                    left++;right--;
                }else if(twoSum > target) right--;
                else left++;
            }
        }
        return ans;
    }
}
```