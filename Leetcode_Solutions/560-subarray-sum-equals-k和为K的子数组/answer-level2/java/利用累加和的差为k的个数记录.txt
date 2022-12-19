### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        //count记录累加和等于n的个数，如果全为正数则不需要记录个数，只需要标记
        int cur = 0, res = 0;
        count.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            cur += nums[i];
            res += count.getOrDefault(cur - k, 0);  //n个累计和为cur - k，
                                                    //加到cur有count[cur - k]种
            count.put(cur, count.getOrDefault(cur, 0) + 1); //加一
        }
        return res;
    }
}
```