### 解题思路
分两步
1. 把不同的位置标记为 1
    利用异或（x ^= y）
2. 计算1的个数
    x &= (x - 1)会把左右边的1变为0
### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        // 不同的位置标记为1
        x ^= y; 
        //计算1的个数
        //巧用 n&(n-1) 会把最右边的1变为
        int ans = 0;
        while (x != 0) {
            ans++;
            x &= (x - 1);
        }
        return ans;
    }
}
```