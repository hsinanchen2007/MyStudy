### 解题思路


### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        //2层循环取出最大面积
        // int maxArea = 0;
        // for(int i=0;i<height.length;i++)
        //     for(int j=i+1;j<height.length;j++){
        //     maxArea = Math.max(maxArea,Math.min(height[i],height[j])*(j-i));
        //     }
        
        // return maxArea;

        //通过2个指针，指向数组最左和最右下标，向数组中间移动，记录最大面积。
        int maxWater=0, left=0, right=height.length-1;
		while(left<right) {
             maxWater = Math.max(maxWater,(right-left)*Math.min(height[left], height[right]));
			if(height[left]<height[right]) {
               left++;
            }else{
                 right--;
            }
		}
		return maxWater;


    }
}
```