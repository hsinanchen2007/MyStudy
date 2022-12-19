### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = height.length-1;
        int min = 0;
        int sum = 0;
        int num = 0;
        while(max!=min){
            num = (height[max]>height[min]? height[min]:height[max])*(max - min);
            if(num>sum){sum = num;}
            if(height[max]>=height[min]){
                min++;
            }else{max--;}
        }
        return sum;
    }
}
```