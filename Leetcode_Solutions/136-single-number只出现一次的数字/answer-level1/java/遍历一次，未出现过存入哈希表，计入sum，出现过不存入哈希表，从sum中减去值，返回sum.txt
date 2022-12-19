### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
    Set<Integer> set = new HashSet<>();
    int sum = 0;
    for(int ele:nums)
    {
        if(!set.contains(ele))
        {
            sum += ele;
            set.add(ele);
        }
        else
            sum-=ele;
    }
    return sum;
    }
}
```