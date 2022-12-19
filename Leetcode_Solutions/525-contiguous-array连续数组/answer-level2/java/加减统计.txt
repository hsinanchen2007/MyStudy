### 解题思路
使用加减统计

### 代码

```java
class Solution {
    public int findMaxLength(int[] nums) {
        // 遇到1加1，遇到0减1
        // ans的索引下标是cnt的上移到非负数的部分（加上num.length）
        // ans[t]的本身值是第一次到达cnt值时的 数组索引下标
        int[] index = new int[2*nums.length + 1];
        // 要初始化为-2
        Arrays.fill(index, -2);
        index[nums.length] = -1;
        int cnt = 0;
        int maxLen = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 1) {
                cnt++;
            } else if(nums[i] == 0) {
                cnt--;
            }
            if(index[cnt + nums.length] >= -1) {
                maxLen = Math.max(maxLen, i-index[cnt + nums.length]);
            } else{
                index[cnt + nums.length] = i;
            }
        }
        return maxLen;
    }
}
```