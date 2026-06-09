### 解题思路
数组的两头分别设置位置标志，从两头开始缩小范围，找两个数较小的那个位置+1或者-1，再计算面积直到两个标志重合，记录的最大面积既是结果

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int ll = 0;
        int rr = height.length-1;
        int max = 0;
        while (ll!=rr){
            int temp= (rr-ll)*Math.min(height[ll],height[rr]);
            if (temp>max){
                max=temp;
            }
            if (height[ll]<height[rr]){
                ll++;
            }else {
                rr--;
            }
        }
        return max;
    }
}
```