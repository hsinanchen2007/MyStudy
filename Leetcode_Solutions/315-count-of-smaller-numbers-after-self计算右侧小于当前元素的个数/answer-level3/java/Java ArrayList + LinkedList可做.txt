### 解题思路
注意一个是ArrayList 一个是LinkedList，否则会超时

### 代码

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> res = new LinkedList<>();
        List<Integer> dp = new ArrayList<>();
        for (int i = nums.length - 1; i >= 0; i --) {
            int left = 0;
            int right = res.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp.get(mid) < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            dp.add(right, nums[i]);
            res.add(0, right);
        }
        return res;
    }
}
```