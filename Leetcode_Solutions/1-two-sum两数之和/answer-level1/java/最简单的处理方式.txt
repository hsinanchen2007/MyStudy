### 解题思路
这是最简单的方式，通过遍历数组后，在进行内循环，从它本身的下一个下标开始循环继续遍历相加，直到得到结果，
等于指定的值，效率是不怎么高，但是还能能解决一些简单的应用场景的，望大家可以采纳，评论探讨。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        	for (int i = 0; i < nums.length; i++) {
			for (int j = (i+1); j < nums.length; j++) {
				 if((nums[i]+nums[j])==target){
					 return new int []{i,j};
				 }
			}
		}
		 return new int []{};
    }
}
```