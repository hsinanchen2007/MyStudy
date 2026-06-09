### 解题思路
每一位上元素只能出现一次，比如第一位上，1和2都只能出现一次，往后全拍
```
if (set.contains(nums[i])) {
    continue;
}
```

### 代码

```java
class Solution {
    List<List<Integer>> mLists = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        backTrack(nums, 0);
        return mLists;
    }

    private void backTrack(int[] nums, int l) {
        if (nums.length == l) {
            mLists.add(toList(nums));
        }
        Set<Integer> set = new HashSet<>();
        for (int i = l; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                continue;
            }
            set.add(nums[i]);
            swap(nums, i, l);
            backTrack(nums, l + 1);
            swap(nums, i, l);
        }
    }

    private void swap(int[] nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    private List<Integer> toList(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int i : nums) {
            list.add(i);
        }

        return list;
    }
}
```