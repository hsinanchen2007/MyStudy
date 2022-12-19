### 解题思路
就错在了[1,0,1,0,0]这个测试用例
如果有兔子说1，那最多2个1，再有1就是新的颜色了
同理2，3，4，最多有3，4，5个，再有就要重新计数了

### 代码

```java
class Solution {
    public int numRabbits(int[] answers) {
        int[] h = new int[1000];
        int ans = 0;
        for (int a : answers) {
            //没判断这个0的情况，￣□￣｜｜
            if(a == 0) {
                ans++;
                continue;
            }
            h[a]++;
            if(h[a] == a + 1) {
                h[a] = 0;
            } else if(h[a] == 1) {
                ans += a + 1;
            }
        }
        return ans;
    }
}
```
### 时间复杂度 O(N)
### 空间复杂度 O(1000)