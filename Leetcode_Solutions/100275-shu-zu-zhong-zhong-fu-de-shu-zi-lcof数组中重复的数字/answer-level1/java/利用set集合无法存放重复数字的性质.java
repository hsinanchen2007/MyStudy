### 解题思路
利用set集合无法存放重复数字的性质

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
    Set<Integer> set = new HashSet<>();
        int ans = 0;
        set.add(nums[0]);
        int currLength =set.size();
        for (int i = 1; i < nums.length; i++) {
            set.add(nums[i]);
            if (currLength==set.size()){//增加了数字，set长度不变，说明是重复数字
                ans = nums[i];
                break; //符合条件跳出循环
            }
            currLength= set.size();
        }
       return ans;
    }
}
```