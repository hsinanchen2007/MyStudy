### 解题思路
   首先这是一道关于数组的题目，并且通过题目的描述可以知道肯定需要用到所有的元素，所以需要使用到循环结构，于是我们使用java中新增的for循环结构，在其中定义变量num，在每一次循环中，num的值都等于数组元素的值并且随着下一次循环向后移动一个元素。
   当我们判断num为0时，不需要任何操作，而当num不为0时，需要把这个元素重新赋值到数组中，从数组的一个元素开始，这就需要设一个变量idx，来指示重新赋值后的数组的使用情况。当所有的元素都被遍历完成后，需要把重新赋值后仍然没有使用到的数组元素重新赋值为0，这时我们使用while循环结构。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int idx = 0;
        for(int num:nums)
        {
            if(num!=0)
            {
                nums[idx++]=num;
            }
        }
        while(idx<nums.length)
        {
            nums[idx++]=0;
        }
		
        
    }
}
```