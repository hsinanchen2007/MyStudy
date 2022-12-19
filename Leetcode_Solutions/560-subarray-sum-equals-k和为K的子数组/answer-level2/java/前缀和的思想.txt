### 解题思路
自己做的解答是O（n²），不值一提。
这里解释一下前缀和的思想
1. 通过一次遍历就可以得到所有的子数组的和分布，确实很高级
2. 我们从左往后，计算累积和，倘若当前map中存在sum-k，那么肯定存在区间（i,j）使其和为k
3. 换言之，遍历一次后，我们通过累积和的减法可以得到任意一个子数组的和
4. 初始存放一个<0,1>是因为，倘若sum和k相等，那么我们无需从map中寻找0，但是为了适用所有情况，所以我们添加一个<0,1>，还是挺优美的一个解法的。

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int res = 0;
        int sum = 0;
        for(int i = 0;i <  nums.length;i++){
            sum += nums[i];
            if (map.containsKey(sum - k))
                res += map.get(sum - k);
            map.put(sum,map.getOrDefault(sum,0) + 1);
        }
        return res;
    }
}
```