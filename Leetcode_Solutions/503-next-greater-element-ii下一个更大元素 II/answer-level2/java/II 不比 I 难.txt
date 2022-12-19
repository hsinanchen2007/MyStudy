### 解题思路
对于元素x，要求其下一个更大元素，可以使用辅助栈。

与 0496 下一个更大的元素 I 相比，两者有以下三点不同。
1. 允许有重复元素：
	有重复元素，意味着不能使用元素值做为map字典的键，可以考虑使用数组索引做键；
	考虑到节省内存，直接使用数组更好。
	既然，使用索引做键，那么，辅助栈也就不能再存元素值，而应该存索引。
2. 计算所有元素，而不是其中一个子集。
	这样一来，字典即是结果，直接返回字典即可。
3. 循环数组
	可以使用两次遍历数组来模拟。

### 代码

```java

public int[] nextGreaterElements(int[] nums) {
	// 结果
	int ans[] = new int[nums.length];

	// 辅助栈
	Stack<Integer> stack = new Stack<>();

	// 填充字典
	for (int i = 0; i < nums.length; i++) {
		ans[i] = -1;
		while(!stack.isEmpty() && nums[i]>nums[stack.peek()]) {
			ans[stack.pop()] = nums[i];
		}
		stack.push(i);
	}
	for (int i = 0; i < nums.length; i++) {
		while(!stack.isEmpty() && nums[i]>nums[stack.peek()]) {
			ans[stack.pop()] = nums[i];
		}
	}

	return ans;
}

```