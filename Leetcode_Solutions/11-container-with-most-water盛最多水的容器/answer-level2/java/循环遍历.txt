### 解题思路
两条垂直线间可容纳的水必构成一个矩形，也就是找到两条直线，它们围绕的矩形的面积最大，面积=（两条直线的坐标之差）*最短的直线高度。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max=0;
        for(int i=0;i<height.length;i++){
            for(int j=i+1;j<height.length;j++){
                if(height[j]>=height[i]){
            if((j-i)*(height[i])>max){
              max=(j-i)*(height[i]);
            }
            }
            else{
            if((j-i)*(height[j])>max){
              max=(j-i)*(height[j]);
            }
            }
            }
        }

        return max;
    }
}
```