### 解题思路
用数组记录每个数字出现次数，发现某个数字出现两次就返回。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int n = nums.length;
        int[] hash = new int[n];
        for(int i = 0; i < n; i ++){
            if(hash[nums[i]]++ > 0){
                return nums[i];
            }
        }
        return -1;

    }
}
```