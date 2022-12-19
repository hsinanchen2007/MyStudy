### 解题思路
这道题目使用dp算法来处理

![图片.png](https://pic.leetcode-cn.com/f8883f6602109e05e441e2c5ba13785ee2e658319c1815061ca2eaf11f4f8a48-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        cntMap.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            Map<Integer, Integer> nMap = new HashMap<>();
            for (Map.Entry<Integer, Integer> entry : cntMap.entrySet()) {
                int t1 = entry.getKey() + nums[i];
                int count = nMap.getOrDefault(t1, 0);
                nMap.put(t1, count + entry.getValue());
                int t2 = entry.getKey() - nums[i];
                int count2 = nMap.getOrDefault(t2, 0);
                nMap.put(t2, count2 + entry.getValue());
            }
            cntMap = nMap;
        }

        return cntMap.getOrDefault(S, 0);
    }
}
```