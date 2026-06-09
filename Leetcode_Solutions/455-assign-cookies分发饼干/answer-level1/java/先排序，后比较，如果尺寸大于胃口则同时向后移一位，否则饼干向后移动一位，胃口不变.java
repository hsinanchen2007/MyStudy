### 解题思路
先排序，后比较，如果尺寸大于胃口则同时向后移一位，否则饼干向后移动一位，胃口不变

### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int total = 0;
        if (g.length == 0 || s.length == 0 || s[s.length -1] < g[0])
            return total;
        int p1 = 0, p2 = 0;
        int i;
        for (i = 0; i < g.length && p1 < s.length; i++){
            if (g[i] > s[p1])
                i--; //孩子不变
            p1++; //饼干移动一位，因为不论是否满足胃口，饼干都需要移动一位。
        }
        return i;
    }
}
```