### 解题思路
跟上一题一样（如果你选择简单并且让题号按顺序排列的话）
这个用双指针就可以轻松地解决。
一根慢指针用来刷新输入的数组，一根快指针用来遍历元素，就这样整个元素就可以再不用建设新数组的情况下处理完毕。


### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
         if (nums.length == 0) return 0;//防止输入的是空的  
     int i=0;//慢指针标记
     for(int j=0;j<nums.length;j++){
         if(nums[j]!=val){//如果不一样，将数值覆盖进原数组里面。（绝对不会发生重复覆盖。因为i的速度永远比j慢，而由j指引的数组元素返回得数早已经被与i的数组比较了）
             nums[i]=nums[j];
             i++;
         }
     }
     return i;
    }
}
```