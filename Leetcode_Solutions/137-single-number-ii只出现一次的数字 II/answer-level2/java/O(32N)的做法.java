### 解题思路
O(32N)的做法

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        
        int result = 0;
        
        for(int i=0;i < 32;i++)
        {
            int eachBit = 0;
            for(int num :nums)
            {
                eachBit += (num >> i) & 1;
            }
            
            result ^= (eachBit %3) << i;
        }
        
        
        return result;
    }
}
```