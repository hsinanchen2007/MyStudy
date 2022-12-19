### 解题思路
此处撰写解题思路
关键在于：if (i > index && nums[i] == nums[i - 1]) continue;

### 代码

```java
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> list = new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        result.add(new ArrayList<>(list));
        Arrays.sort(nums);
        for (int k = 1; k <= nums.length; k++) {
            trackback(nums, k, 0);
        }
        return result;
    }

    public void trackback(int[] nums, int k, int index) {
        if (list.size() == k) {
            result.add(new ArrayList<>(list));
            return;
        }
        for (int i = index; i < nums.length; i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            list.add(nums[i]);
            trackback(nums, k, i + 1);
            list.remove(list.size() - 1);
        }
    }
}
```