### 解题思路
此处撰写解题思路
也可以定mid，双指针left&right
执行用时 :
28 ms
, 在所有 Java 提交中击败了
71.63%
的用户
内存消耗 :
43.3 MB
, 在所有 Java 提交中击败了
99.87%
的用户
### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        int len = nums.length;
        for (int i = 0; i < len - 2 ;i++){
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int mid = i + 1;
            int right = len - 1;
            while (mid < right){
                int sum = nums[i] + nums[mid] + nums[right];
                if (sum < 0) while (mid < right && nums[mid] == nums[++mid]);
                else if (sum > 0) while (mid < right && nums[right] == nums[--right]);
                else{
                    res.add(new ArrayList<Integer>(Arrays.asList(nums[i], nums[mid], nums[right])));
                    while (mid < right && nums[mid] == nums[++mid]);
                    while (mid < right && nums[right] == nums[--right]);
                }
            }
        }
        return res;
    }
}
```