### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    Set<List<Integer>> set = new HashSet<>();

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            int tmp = nums[i];
            int begin = i + 1;
            int end = nums.length - 1;
            while (begin < end) {
                int sum = tmp + nums[begin] + nums[end];
                if (sum == 0) {
                    List<Integer> list = new ArrayList<>();
                    list.add(tmp);
                    list.add(nums[begin]);
                    list.add(nums[end]);
                    set.add(list);
                    end--;
                    begin++;
                } else if (sum > 0) {
                    end--;
                } else {
                    begin++;
                }
            }
        }
        return new ArrayList<>(set);
    }
}
```