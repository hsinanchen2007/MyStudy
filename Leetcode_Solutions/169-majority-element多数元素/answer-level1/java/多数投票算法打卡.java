### 解题思路
剑指offer有一道原题，当时就学习了多数投票算法，这次直接写代码。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count=0;
        int m=0;
        for(int num:nums)
        {
            if(count==0)
            {
                count++;
                m=num;
            }
            else if(m==num)
            {
                count++;
            }
            else
            count--;
        }
        return m;
    }
}
```
### 复杂度
- 时间复杂度：O(N)，遍历一次
- 空间复杂度：O(1)