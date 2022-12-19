### 解题思路

第一个取nums[0]，后面不停地像前一个排好队的数组插队,插入的可能是插在前一个队伍的任意位置。

[[1]]->[[1,2],[2,1]]->[[3, 2, 1], [2, 3, 1], [2, 1, 3], [3, 1, 2], [1, 3, 2], [1, 2, 3]]

### 代码

```java
class Solution {
    public List<List<Integer>> fc(List<List<Integer>> nums, int c) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= nums.get(i).size(); j++) {
                List<Integer> temp = new ArrayList<>(nums.get(i));
                temp.add(j, c);
                result.add(temp);
            }
        }
        return result;
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums.length == 0) {
            return result;
        }
        List<Integer> to = new ArrayList<>();
        to.add(nums[0]);
        result.add(to);
        for (int i = 1; i < nums.length; i++) {
            result = fc(result, nums[i]);
        }
        return result;
    }
}
```