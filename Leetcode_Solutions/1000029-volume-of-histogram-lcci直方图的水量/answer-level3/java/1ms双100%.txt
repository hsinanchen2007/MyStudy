### 解题思路
算是动态规划？不太确定。
先找出最高点坐标
以最高点位分分界，两边求解
一直更新左边最高的高度，而右边的高度肯定会一直保持高于左边，
然后每个坐标点的积水量就是当前左边最高点的高度减去当前点的高度。
右边跟这个对称。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int max=0;
        int max_Index=0;
        for (int i=0;i<height.length;i++){
            if (height[i]>max){
                max=height[i];
                max_Index=i;
            }
        }
        int sum=0;
        int left=0;
        for (int i=0;i<max_Index;i++){
            if (height[i]>=left)
                left=height[i];
            else
                sum+=(left-height[i]);
        }
        left=0;
        for (int i=height.length-1;i>max_Index;i--){
            if (height[i]>=left)
                left=height[i];
            else
                sum+=(left-height[i]);
        }
        return sum;
    }
}
```