### 解题思路
一切尽在代码中

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
       List<List<Integer>> result = new ArrayList();
        int length = nums.length;
        if(nums.length < 3)
            return result;

        Arrays.sort(nums);
        if(nums[0] > 0){
            return result;
        }

        for(int i = 0; i < length - 2; i++){
            //去重,排序过后  相同的值都在一起
            if(i > 0 && nums[i] == nums[ i - 1]){
                continue;
            }
            int middle = i + 1;
            int end = length - 1;
            int sum = -nums[i];
            while (middle < end){
                if (nums[middle] + nums[end] + nums[i] < 0 || (middle > i + 1 && nums[middle] == nums[middle - 1])) {
                    middle++;
                } else {
                    if (nums[middle] + nums[end] + nums[i] > 0 || (end < nums.length - 1 && nums[end] == nums[end + 1])) {
                        end--;
                    } else {
                        result.add(Arrays.asList(nums[i], nums[middle], nums[end]));
                        middle++;
                        end--;
                    }
                }
            }
        }
        return result;
        }
}
```