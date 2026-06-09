### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; i++){
            if(set.add(nums[i]) == false)
                return nums[i];
        }
        return -1;
    }
}
```