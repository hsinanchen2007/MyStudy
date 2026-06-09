### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reachNumber(int target) {
        int sum = 0;
        int i = 0;
        int ans = Math.abs(target);
        while(sum < ans || (sum - ans) % 2 != 0) {
            sum += i;
            i++;
        }
        return i-1;
    }
}
```