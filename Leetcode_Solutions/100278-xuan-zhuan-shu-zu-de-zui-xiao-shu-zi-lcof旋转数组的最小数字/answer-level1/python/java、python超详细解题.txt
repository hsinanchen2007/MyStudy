## 解题分析
这道题，抽象成计算机思路的话，其实就是寻找第一个变小的数字，如果都没有的话，就是没有旋转或者旋转了一整个，直接返回第一位即可；

大家的第一想法应该都是，直接遍历数组，找到第一个变小的数字返回即可，这样话，最坏的情况，我们需要遍历整个数组，时间复杂度为O(n)，这显然不是最优的解法；

一般看到这种排序数组之类的字样，我们就应该下意识的想到可能和**二分法**有关；

- 定义一个左右指针，分别指向数组的左右端点；
- 进入循环，判断左指针在右指针左边，并算出左右指针的中间节点，如果是偶数的话取左边的节点；
- 如果中间节点的值大于末尾节点，说明旋转点还在后面，左节点指向中间节点的下一个节点；
- 如果中间节点的值小于末尾节点，有两种情况，当前节点就是转折点或者转折点还在左边，我们把右节点指向中间节点；
- 如果中间节点的值等于末尾节点，也有两种情况，此时中间节点在末尾节点左边，或者中间节点和末尾节点重合了，我们只需要向右移动一次右节点即可，如果是重合了，就会跳出循环，如果在左边，右移之后就会进入条件1；

## 代码
ps：这里笔者使用的jdk为1.8、python3.7

- java实现

	```java
	class Solution {
	    public int minArray(int[] numbers) {
	        int left = 0;
	        int right = numbers.length - 1;
	        // 数组被旋转了一整个
	        if (numbers[left] < numbers[right]) {
	            return numbers[left];
	        }
	        while (left < right) {
	            int mid = (left + right) / 2;
	            if (numbers[mid] < numbers[right]) {
	                right = mid;
	            } else if (numbers[mid] > numbers[right]) {
	                left = mid + 1;
	            } else {
	                right--;
	            }
	        }
	
	        return numbers[right];
	    }
	}
	```

- python实现

	```python
	class Solution:
	    def minArray(self, numbers: List[int]) -> int:
	        left = 0
	        right = len(numbers) - 1
	        while left < right:
	            mid = (left + right) // 2
	            if numbers[mid] > numbers[right]:
	                left = mid + 1
	            elif numbers[mid] < numbers[right]:
	                right = mid
	            else:
	                right -= 1
	        return numbers[left]
	```