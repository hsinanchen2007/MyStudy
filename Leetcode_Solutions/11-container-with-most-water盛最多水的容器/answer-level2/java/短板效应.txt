### 解题思路
利用双指针遍历法

### 代码

```java
class Solution {
    public int maxArea(int[] array) {
         int low=0;//首指针
        int high=array.length-1;//尾指针
        int max=0;//最大值

        while (low<high){
            //求最大值，指针会在下面移动
            max=Math.max(max,Math.min(array[low],array[high])*(high-low));
            //移动比较短的指针(短板效应)
            if (array[low]<array[high]){
                low++;
            }
            else {
                high--;
            }
        }
        return max;
    }
}
```