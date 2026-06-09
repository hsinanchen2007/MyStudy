### 解题思路
每根柱子能接的雨水等于min[左边最高柱子的高度：右边最高柱子的高度]-柱子本身的高度，例如[5,2,3],第二根柱子能接的雨水=min[5,3]-2=1,用一个for循环从第二根柱子计算到倒数第二根柱子，如果min的值小于柱子本身的高度，则舍弃本根柱子，然后把所有柱子能接的雨水加起来。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int min,max1,max2,sum=0;
        //如果柱子为空或者数目小于3，则不能接雨水
        if(height == null || height.length < 3){
            return 0;
        }
        //第一根和最后一根不能接雨水，从第二根柱子计算到倒数第二根柱子
        for(int i=1;i<height.length-1;i++){
          //找到左边最高的柱子
           max1=height[0];
            for(int j=0;j<i;j++){
               if(height[j]>max1)
              max1=height[j];
            }
            //找到右边最高的柱子
            max2=height[i+1];
            for(int j=i+1;j<height.length;j++){
                if(height[j]>max2)
                max2=height[j];
            }
            //将计算出来的最短柱子的高度赋值给min
            min=max1<max2?max1:max2;
           //只有min大于当前柱子的高度，才能接雨水，否则舍弃本根柱子
           if(height[i]<=min)
            sum+=min-height[i];
           //舍弃
         else{
             sum+=0;
           }
        }
        return sum;
    }
}
```