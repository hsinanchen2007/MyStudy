### 解题思路
* 用散列表来维护这个k大小的滑动窗口。
* 当哈希表中个数大于k时，删除i-k之前的数据（初等数学知识）

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
             if(set.contains(nums[i])) {
                 return true;
             }
            set.add(nums[i]);
            if(set.size() > k) {
                set.remove(nums[i-k]);
            }
        }
        return false;
    }
}
```