### 解题思路


### 代码

```java
class Solution {
    //借鉴的别人的答案。。
    //这题关键是读懂题目含义，
    // 让所有开着的灯都变成蓝色的时刻的性质是：此时点亮最远的灯的位置恰巧等于点亮灯的个数。
    // 若点亮最远的灯的位置大于此时点亮灯的个数，则意味着在点亮最远的灯的位置之前存在着未点亮的灯。
    public int numTimesAllBlue(int[] light) {
        int size = light.length;
        int count = 0, maxReachingPoint = 0;
        for (int i = 0 ; i < size; i++){
            maxReachingPoint = Math.max(maxReachingPoint, light[i]);
            if ( i + 1 == maxReachingPoint){
                count += 1;
            }
        }
        return count;
    }
}
```