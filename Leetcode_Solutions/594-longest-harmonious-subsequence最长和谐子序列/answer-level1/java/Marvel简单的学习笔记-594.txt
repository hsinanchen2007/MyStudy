### 一次for循环即可
使用一个哈希表保存数字与其出现次数的映射。
扫描数组中的每个数字，添加或更新到哈希表中，随后对该数字 i，若哈希表存在数字 i-1 的映射，则计算 i 出现次数与 i-1 出现次数的和；同理，若存在数字 i+1 的映射，则计算 i 出现次数与 i+1 出现次数的和。这样，我们得到了两个和，将较大者作为最大长度。如此这般，对每个数字都重复上述操作，不断更新最大长度，当最后一个数字处理完时，得到的最大长度就是最终答案。

时间复杂度：O(n)。
空间复杂度：O(n)。要存放所有数字及其出现次数的映射。

### 代码

```java
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int LL = 0;
        for(int i : nums)
        {
            if(map.containsKey(i))  
                map.put(i, map.get(i)+1);
            else                    
                map.put(i, 1);
            if(map.containsKey(i - 1))
                LL = Math.max(LL, map.get(i) + map.get(i - 1));
            if(map.containsKey(i + 1))
                LL = Math.max(LL, map.get(i) + map.get(i + 1));
        }
        return LL;
    }
}
```