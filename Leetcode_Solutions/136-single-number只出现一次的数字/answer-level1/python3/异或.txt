## 思路:

异或就可以了

```python [1]
def singleNumber(self, nums: List[int]) -> int:
        res = nums[0]
        for num in nums[1:]:
            res ^= num
        return res
```



```java [1]
class Solution {
    public int singleNumber(int[] nums) {
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) res ^= nums[i];
        return res;
    }
}
```

