### 解题思路

遍历i<n, 根据边界情况划分:
- 当前元素右边界小于新的左边界, 说明全部都在左边没有交集, 否则下一步
- 当前元素的左边界小于等于新的右边界, 说明存在交叉元素, 此时只存在一个元素
- 当前元素的左边界大于新的右边界, 说明全部在右边不存在交集

### 代码

```java
class Solution {
    public int[][] insert(int[][] nums, int[] newInterval) {
        List<int[]> result = new ArrayList<>();
        int index = 0, n = nums.length;
        // 当前右边界小于新的左边界, 无交集
        while(index < n && nums[index][1] < newInterval[0]){
            // 先把val[1] < newVal[0]即左边的压入
            result.add(nums[index]);
            index++;
        }
        int start = newInterval[0];
        int end = newInterval[1];
        // 存在交集, 当前元素的左边界小于新的右边界, 则都需要合并
        while(index < n && nums[index][0] <= newInterval[1]){
            start = Math.min(start, nums[index][0]);
            end = Math.max(end, nums[index][1]);
            index++;
        }
        result.add(new int[]{start, end});
        // 当前元素的左边界大于新的右边界, 则不需要合并
        while(index < n){
            result.add(nums[index]);
            index++;
        }
        int[][] res = new int[result.size()][2];
        index = 0;
        for(int[] tmp: result){
            res[index++] = tmp;
        }
        return res;
    }
}
```