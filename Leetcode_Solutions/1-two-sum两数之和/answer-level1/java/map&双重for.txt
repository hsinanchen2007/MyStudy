### 解题思路
此处撰写解题思路

### 代码

```java

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[] = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0 ; i < nums.length ; i++){
            if (map.containsKey(target - nums[i])) {
                ans[0] = map.get(target - nums[i]);
                ans[1] = i;
                return ans;
            }
            map.put(nums[i], i);
        }
        return ans;
    }
}
/*  暴力版
     int ans[] = new int[2];
        for (int i = 0 ; i < nums.length ; i++){
            for (int j = 0 ; j < nums.length ; j++){
                if (i != j && (nums[i] + nums[j]) == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
*/
```