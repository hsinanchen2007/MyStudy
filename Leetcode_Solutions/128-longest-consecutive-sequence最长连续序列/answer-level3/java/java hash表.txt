### 解题思路
使用RectRecord记录当前最长的区间，然后用两个hash表分别记录。每insert一个数，都会调整区间，同时调整索引hash表。
调整的方法有四种情况：
[?, num-1]存在，向左合并
[num+1,?]存在， 向右合并
[?, num-1]、[num+1,?]都存在，两端都需要合并
[?, num-1]、[num+1,?]都不存在，不需要合并，直接原地记录
最大区间就是最后的答案

### 代码

```java

/**
 * Solution, LeetCode
 *
 * @author jianghe
 * @since 2020-03-29
 */
class Solution {
    public int longestConsecutive(int[] nums) {
        int max = 0;
        Set<Integer> used = new HashSet<>();

        // 以key开始的最大范围
        Map<Integer, RectRecord> startRecord = new HashMap<>();
        // 以key结尾的最大范围
        Map<Integer, RectRecord> endRecord = new HashMap<>();

        for (int num : nums) {
            if (used.contains(num)) {
                continue;
            }
            used.add(num);
            RectRecord rect = new RectRecord(num, num);
            // 加入num进行动态调整
            RectRecord rightRect = startRecord.remove(num + 1);
            RectRecord leftRect = endRecord.remove(num - 1);
            if (rightRect != null && leftRect != null) {
                // 左右需要合并
                rect.left = leftRect.left;
                rect.right = rightRect.right;
            } else if (rightRect != null) {
                // 右边可以merge
                rect.right = rightRect.right;
            } else if (leftRect != null) {
                // 左边可以merge
                rect.left = leftRect.left;
            }
            startRecord.put(rect.left, rect);
            endRecord.put(rect.right, rect);
            max = Math.max(max, rect.right - rect.left + 1);
        }
        return max;
    }

    static class RectRecord {
        int left;
        int right;

        RectRecord(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }
}
```