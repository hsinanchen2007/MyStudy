### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Set <Integer> set=new HashSet<Integer>();
        for(int i:nums)
        {
            if(!set.contains(target-i))
                set.add(i);
            else
            {
                return new int []{i,target-i};
            }
        }
        return new int[]{};
    }
}
```