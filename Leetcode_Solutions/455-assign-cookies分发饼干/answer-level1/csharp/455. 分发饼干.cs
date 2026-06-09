### 解题思路
数组排序，一次遍历

### 代码

```csharp
public class Solution {
    public int FindContentChildren(int[] g, int[] s) {
        if (g.Length == 0 || s.Length == 0) return 0;

        Array.Sort(g);
        Array.Sort(s);
        int child = 0;
        int cookie = 0;
        while (child < g.Length && cookie < s.Length)
        {
            if (s[cookie] >= g[child]) child++;
            cookie++;
        }
        return child;
    }
}
```