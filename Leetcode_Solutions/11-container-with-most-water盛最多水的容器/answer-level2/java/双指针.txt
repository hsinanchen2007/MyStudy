//找到左右两边最小的柱子，大柱子不动，小柱子往内收敛一个算面积比大小
//如此循环;

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int i = 0;
        int j = height.length - 1;
        while(i < j){
            //找到左右两边最小的柱子，大柱子不动，小柱子往内收敛一个算面积比大小
            //如此循环;
            max = height[i] < height[j] ?
                Math.max(max, (j - i) * height[i++]):
                Math.max(max, (j - i) * height[j--]);
        }
        return max;
    }
}
```