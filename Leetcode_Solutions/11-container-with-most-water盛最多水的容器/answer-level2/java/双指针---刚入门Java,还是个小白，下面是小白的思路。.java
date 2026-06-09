### 解题思路
此处撰写解题思路

### 代码
![2019120501.PNG](https://pic.leetcode-cn.com/0f60e386e1ffb31cb5113c9e47fe7bd4fd53a70bbc7cd1669350ff3bb3430a1a-2019120501.PNG)

```java
class Solution {
    public int maxArea(int[] height) {
        int maxValue = 0;//在遍历过程成记录最大值
        //双指针遍历数组
        int i =0;//从左边开始遍历的左指针
        int j = height.length-1;//从右边开始遍历的右指针
        while(i<j) {//循环终止条件
        	if(height[i]<=height[j]) {//当左边的数小于右边的数时，左指针向右边移动，i++.
                if(maxValue<(j-i)*height[i]){//计算此时的容器面积
                    maxValue = (j-i)*height[i];//maxValue随时更新容器面积的最大值
                }
        		i++;
        	}else if(height[i]>height[j]) {//当右边的数小于左边的数时，右指针向左边移动，j--.
                if(maxValue<(j-i)*height[j]){//计算此时的容器面积
                    maxValue = (j-i)*height[j];//maxValue随时更新容器面积的最大值
                }
        		j--;
        	}
        }
        return maxValue;
    }
}
```