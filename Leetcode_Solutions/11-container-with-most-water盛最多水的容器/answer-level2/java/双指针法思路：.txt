### 解题思路
假设x轴为长，y轴为宽
1）首先长为（数组长度-1）的矩形只有唯一一个；2）长为（数组长度-2）的矩形只有两个
在第一种情况下选择宽最短的进行平移，就是选择了2）情况下具有较大面积矩形的一种情况。
以此类推...

### 代码

```java
public class Solution {
    public int maxArea(int[] height) {
        int max=0,size;
        int l=0,r=height.length-1;
        while(l<r){
            size=(r-l)*Math.min(height[l],height[r]);
            if(size>max)
                max=size;
            if(height[l]>height[r])
                r--;
            else
                l++;
        }
        return max;
    }
}

```