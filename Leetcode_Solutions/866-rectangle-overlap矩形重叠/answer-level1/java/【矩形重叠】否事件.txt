### 解题思路
这题如果正面考虑的话，需要讨论非常多的情况，容易漏解，这个时候我们可以从反面出发，如果我们能方便地分析出**不重叠**的情况，那么最后将结果取反就行。对于这道题，**不重叠**的情况是比较好判断的：不妨固定矩形`rec1`，如果矩形`rec1`与矩形`rec2`不重叠，显然`rec2`将有以下四种情况：
> - **`rec2-1:`** $rec1[0] ≥ rec2[2]$
> - **`rec2-2:`** $rec1[1] ≥ rec2[3]$
> - **`rec2-3:`** $rec1[2] ≤ rec2[0]$
> - **`rec2-4:`** $rec1[3] ≤ rec2[1]$

![image.png](https://pic.leetcode-cn.com/19cf8adad4ffac3297399a80dd49cbef2caa7163b0cfa1c456c05d76367386e3-image.png)

也就是说，**两矩形不重叠**的情况应该是：
$rec1[0] ≥ rec2[2] \ || \ rec1[1] ≥ rec2[3] \ || \ rec1[2] ≤ rec2[0] \ || \ rec1[3] ≤ rec2[1]$
**重叠**的情况只需将上述表达式取非即可。


### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec1[2] <= rec2[0] || rec1[3] <= rec2[1]);
    }
}
```