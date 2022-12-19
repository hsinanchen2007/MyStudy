### 解题思路
先从暴力算法简单的入手，然后考虑到条件能否优化？因为数组是有序的，数组的值都是单调递增的，所以我们先判断数组的头尾两个元素相加是否等于target，numbers[low]+numbers[high]=target？如果是，那么我们就找到了唯一的解，直接退出循环；如果相加大于target，因为值是单调递增的，所以应该降低high的值，让两数相加之和接近于target；如果相遇target，那么应该增加low的值，让两数之和接近于target。思路很简单，一层循环就结束了，判断条件就是low<high，因为是递增的，而且不能是同一个数。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0, high = numbers.length - 1;
		while(low < high) {
			if(numbers[low] + numbers[high] > target)
				high--;
			if(numbers[low] + numbers[high] < target)
				low ++;
			if(numbers[low] + numbers[high] == target)
				return new int[] {low+1, high+1};
		}
        return null;
    }
}
```