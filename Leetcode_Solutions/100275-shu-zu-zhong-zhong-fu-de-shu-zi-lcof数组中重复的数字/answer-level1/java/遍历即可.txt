### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int n = nums.length;
        int[] chars = new int[n];
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(++chars[nums[i]] > 1) {
                res = nums[i];
                break;
            }
        }
            
        return res;
    }
}
```