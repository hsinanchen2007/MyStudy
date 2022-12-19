### 解题思路
1. 设立两个变量，分别存储左右遍历的位置
2. 计算出当前的面积并与当前的max相比较
3. 为了寻求最大的面积，我们比较height[i]和height[j]，如果height[i]>height[j],那么j--，反之，i++.

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int i = 0;
        int j = height.length - 1;
        while (i < j){
            int temp = Math.min(height[i],height[j]) * (j-i);
            if (temp > max)
                max = temp;
            if (height[i] < height[j])
                i++;
            else 
                j--;
        }
        return max;
    }
}
```