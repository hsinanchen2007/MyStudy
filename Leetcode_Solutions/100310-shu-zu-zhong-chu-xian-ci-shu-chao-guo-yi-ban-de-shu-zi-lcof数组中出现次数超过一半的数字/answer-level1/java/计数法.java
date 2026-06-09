### 解题思路
当前数字计数cnt，当cnt==0，换数，与之相同++，不同--

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int res = 0,cnt = 0;
        for (int i=0;i<nums.length;i++) {
            if (cnt>0) {
                if (nums[i] == res) {
                    cnt++;
                } else {
                    cnt--;
                }
            } else {
                res = nums[i];
                cnt++;
            }
        }
        return res;
    }
}
```