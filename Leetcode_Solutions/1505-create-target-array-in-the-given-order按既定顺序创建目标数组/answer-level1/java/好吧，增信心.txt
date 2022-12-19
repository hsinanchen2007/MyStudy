### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> lists = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            lists.add(index[i], nums[i]);
        }
        int[] results = new int[lists.size()];
        for (int i = 0; i < results.length; i++) {
            results[i] = lists.get(i);
        }
        return results;
    }
}
```