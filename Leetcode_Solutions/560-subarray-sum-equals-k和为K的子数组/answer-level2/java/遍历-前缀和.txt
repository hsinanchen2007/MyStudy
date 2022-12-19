### 解题思路
1、最简单的方法，直接遍历，计算以nums的每个值开始的连续序列的和是否为k，时间复杂度O(n^2),比较低效。

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count=0;
        for (int i=0; i<nums.length; i++) {
            int j=i, sum=0;
            while (j<nums.length) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
                j++;
            }
        }
        return count;

    }
}
```

### 解题思路
2、前缀和。时间复杂度O(n)
假设区间[left, right]的和为k,即前right项的和-前left项的和=k,换句话说就是：前left项之和=前right项之和-k.
    
因此我们可以遍历一遍数组，记录下前i项的和sum,用Map的健存储sum，Map的值存储sum出现的次数。

假设当前扫到第i位，记录它的前i项和sum，用该和减去k，即sum-k，判断sum-k是否为某个位置的前n项和，若是，更新统计量。

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count=0;
        Map<Integer, Integer> map = new HashMap<>();
        int sum=0;
        map.put(0, 1);
        for (int i=0; i<nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum-k)) {
                count += map.get(sum-k);
            }
            if (map.containsKey(sum)) {
                map.put(sum, map.get(sum) + 1);
            } else {
                map.put(sum, 1);
            }
            
        }
        return count;
    }
}
```