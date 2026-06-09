### 解题思路
解法参考三数之和，注意最大值与最小值的判断。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for(int m = 0; m < nums.length-3; m++){
            if(nums[m] + nums[m+1] + nums[m+2] + nums[m+3]  > target) break;
            if(nums[m] + nums[nums.length-3] + nums[nums.length-2] + nums[nums.length-1]  < target) continue;
            if(m > 0 && nums[m-1] == nums[m]) continue;
           for(int n = m + 1; n < nums.length-2; n++){
               if(nums[m] + nums[n] + nums[n+1] + nums[n+2]  > target) break;
               if(nums[m] + nums[n] + nums[nums.length-2] + nums[nums.length-1]  < target) continue;
               if(n > 1 && nums[n-1] == nums[n] && n-1 != m) continue;
               int i = n+1, j = nums.length - 1;
               while(i < j){
                   int sum = nums[m] + nums[n] + nums[i] + nums[j];
                   if(sum == target){ // 记录，i 右移，j左移。
                       res.add(new ArrayList<Integer>(Arrays.asList(nums[m], nums[n], nums[i], nums[j])));
                       while(i < j && nums[i] == nums[++i]); //跳过重复的值，左移 +1 ，右移 -1 。
                       while(i < j && nums[j] == nums[--j]);
                   }else if(sum > target){//j左移。
                       while(i < j && nums[j] == nums[--j]);
                   }else{//i 右移。
                       while(i < j && nums[i] == nums[++i]);
                   }
               }
            }
        }
        return res;
    }
}
```