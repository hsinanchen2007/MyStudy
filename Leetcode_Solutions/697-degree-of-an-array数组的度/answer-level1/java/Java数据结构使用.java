### 解题思路
使用Java8的特性，使用map暂存每个数的下标地址，之后获取出来长度的value(其实就是最大的度)的集合(有可能为多个下标集合)，之后获取其中最小长度就行

### 代码

```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        // values按照长度进行归类
        Map<Integer, List<List<Integer>>> groups = map.values().stream().collect(Collectors.groupingBy(List::size));
        // 获取最大的长度
        int maxDu = groups.keySet().stream().max(Integer::compareTo).orElse(1);
        // 拥有最大的度的下标集合
        List<List<Integer>> lists = groups.get(maxDu);
        int minLen = Integer.MAX_VALUE;
        for (List<Integer> maxList : lists) {
           // 获取每个最小的连续子数组的长度
            minLen = Math.min(maxList.get(maxList.size() - 1) - maxList.get(0) + 1, minLen);
            if (minLen == 2) {
                return 2;
            }
        }
        return minLen;
    }
}
```