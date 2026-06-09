### 解题思路
最终要移动到一个，所以无论什么数组，最终都要看2变1。
c# 简单解法，期待大神给出更好的算法
![image.png](https://pic.leetcode-cn.com/fc654f976162198d26593cdd82afdacf2af66ccea07408a7ce9f7ddab034b61d-image.png)


### 代码

```csharp
public class Solution {
    public int MinCostToMoveChips(int[] chips) {
        var ji=chips.Where(x=>x%2>0);
        var ou=chips.Where(x=>x%2==0);
        int jiCount=ji.Count();
        int ouCount=ou.Count();
        return jiCount>ouCount?ouCount:jiCount;
    }
}
```