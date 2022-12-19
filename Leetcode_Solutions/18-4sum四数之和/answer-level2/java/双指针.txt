### 解题思路
和三数之和一样，多加了一重循环，同时要注意排除a,b的重复情况

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        int len = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        if (len < 4) return res;
        int a = 0, b = 1, c = 2, d = len - 1;
        for (a = 0; a < len - 3; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (b = a + 1; b < len - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                c = b + 1;
                d = len - 1;
                while (c < d) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum < target) {
                        c++;
                    } else if (sum > target) {
                        d--;
                    } else {
                        List<Integer> l = new ArrayList<>();
                        l.add(nums[a]);
                        l.add(nums[b]);
                        l.add(nums[c]);
                        l.add(nums[d]);
                        res.add(l);
                        while (c < d && nums[c] == nums[c + 1]) c++;
                        c++;
                        while (d > c && nums[d] == nums[d - 1]) d--;
                        d--;
                    }
                }
            }
        }
        return res;
    }
}
```