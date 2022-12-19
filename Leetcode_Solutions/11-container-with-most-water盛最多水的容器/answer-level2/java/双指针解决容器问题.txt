### 解题思路
在每一个状态下，无论长板或短板收窄 1 格，都会导致水槽 底边宽度 -1：
1.若向内移动短板，水槽的短板 min(h[i],h[j]) 可能变大，因此水槽面积 S(i,j) 可能增大。
2.若向内移动长板，水槽的短板 min(h[i],h[j]) 不变或变小，下个水槽的面积一定小于当前水槽面积。



### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int res = 0;
        while(i<j){
            res = height[i]<height[j]?Math.max(res, (j-i)*height[i++]):Math.max(res, (j-i)*height[j--]);
        }
        return res;
    }
}
```