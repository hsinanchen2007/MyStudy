### 解题思路
双指针向中间夹，不会错过最优解。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int p1=0;
        int p2=height.length-1;
        int max=0;
        while(p1<p2){
            int val=(p2-p1)*Math.min(height[p1],height[p2]);
            if(val>max){
                max=val;
            }
            if(height[p1]>=height[p2]){
                p2--;               
            }else{
                p1++;
            }            
        }
        return max;
    }
}
```