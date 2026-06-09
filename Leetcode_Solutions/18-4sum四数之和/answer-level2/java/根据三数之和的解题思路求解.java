### 解题思路
按照之前三数之和的解题思路进行，由于是有序的，对加入的结果集进行了去重处理。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int numsLen = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        if (numsLen < 4) {
            return result;
        }
        Arrays.sort(nums);
        for (int i = 0 ; i < numsLen; i++) {
            for (int j = i + 1; j < numsLen; j++) {
                int left = j + 1;
                int right = numsLen - 1;
                while (left  < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        List<Integer> tupleList = Arrays.asList(nums[i], nums[j], nums[left], nums[right]);
                        if (!result.contains(tupleList)) {
                            result.add(tupleList);
                        }
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
}
```