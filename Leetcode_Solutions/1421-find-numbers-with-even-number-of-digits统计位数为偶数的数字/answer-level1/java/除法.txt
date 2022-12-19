### 解题思路
使用除法比计算字符串长度整体性能搞很多，其中使用与运算来计算数字是否为偶数，相对于取模快很多

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            int bit = 0;
            while (num != 0) {
                bit++;
                num /= 10;
            }
            
            if ((bit & 1) == 0) {
                ans++;
            }
        }
        
        return ans;
    }
}
```