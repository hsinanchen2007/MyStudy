假如从第start家开始考虑打劫，你可选择start或start+1，打劫一家，休息一场，从再往后一家开始考虑，迭代求解。
`res@start = Math.max(nums[start] + rob(nums, start + 2), nums[start+1] + rob(nums, start + 3));`
由于同一start在计算过程可能出现多次，使用HashMap缓存阶段结果，优化时间。

```java
class Solution {
    private Map<Integer, Integer> cache = new HashMap();
    public int rob(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        cache.put(nums.length -1, nums[nums.length-1]);
        cache.put(nums.length, 0);
        cache.put(nums.length + 1, 0);
        return rob(nums, 0);
    }
    
    public int rob(int[] nums, int start) {
        if(cache.containsKey(start)) {
            return cache.get(start);
        }
        int res = Math.max(nums[start] + rob(nums, start + 2), nums[start+1] + rob(nums, start + 3));
        cache.put(start, res);
        return res;
    }
}
```
