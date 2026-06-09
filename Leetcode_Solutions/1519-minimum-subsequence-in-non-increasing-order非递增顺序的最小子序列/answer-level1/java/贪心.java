### 解题思路
排序，优先选择最大的数

### 代码

```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums);
        int sum = 0;
        for (int i:nums) {
            sum += i;
        }
        int temp = 0;
        for (int i=nums.length-1; i>=0; i--) {
            if (sum%2 == 0 && temp <= sum/2) {
                temp += nums[i];
                list.add(nums[i]);
            } else if (sum%2 == 1 && temp < sum/2 + 1) {
                temp += nums[i];
                list.add(nums[i]);
            } else {
                break;
            }
        }
        return list;
    }
}
```