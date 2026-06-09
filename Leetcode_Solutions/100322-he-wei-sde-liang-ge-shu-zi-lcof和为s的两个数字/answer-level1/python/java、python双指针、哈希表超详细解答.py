## 解题分析
首先题目中是对一个排序数组进行操作，这时候最有效的方法就是使用左右指针，我们定义一个左指针left指向0，右指针right指向数组的最后，相加左右指针上的元素，如果比目标值要大，说明我们要变小，那么就右指针左移；如果比目标值小了，说明我们要变大，那么就左指针右移，相等了就直接返回结果即可；

---
如果不是排序数组，我们可以使用哈希表来做，我们定义一个set，遍历数组的时候，看下目标值减去当前元素在set中是否存在，存在的话就返回两个值，不存在的话就将当前元素放入set中即可

两种做法的时间复杂度都是O(n)，第二种应对非排序数组的做法需要额外的O(n)的空间;

## 代码
ps：这里笔者使用的jdk为1.8、python3.7

### 双指针法
- java实现
	```java
	class Solution {
	    public int[] twoSum(int[] nums, int target) {
	        if (Objects.isNull(nums) || nums.length == 0) {
	            return new int[]{};
	        }
	        int left = 0;
	        int right = nums.length - 1;
	        while (left < right) {
	            if (target > nums[left] + nums[right]) {
	                left++;
	            } else if (target < nums[left] + nums[right]) {
	                right--;
	            } else {
	                return new int[]{nums[left], nums[right]};
	            }
	        }
	        return new int[]{};
	    }
	}
	```

- python实现

	```python
	class Solution:
	    def twoSum(self, nums: List[int], target: int) -> List[int]:
	        if nums is None or len(nums) == 0:
	            return []
	        left = 0
	        right = len(nums) - 1
	        while left < right:
	            if target > nums[left] + nums[right]:
	                left += 1
	            elif target < nums[left] + nums[right]:
	                right -= 1
	            else:
	                return [nums[left], nums[right]]
	```


### 哈希表（无序数组最优解）
- java实现
	```java
	class Solution {
	    public int[] twoSum(int[] nums, int target) {
	        if (Objects.isNull(nums) || nums.length == 0) {
	            return new int[]{};
	        }
	        Set<Integer> set = new HashSet<>();
	        for (int num : nums) {
	            if (set.contains(target - num)) {
	                return new int[]{num, target - num};
	            }
	            set.add(num);
	        }
	        return new int[]{};
	    }
	}
	```
- python实现

	```python
	class Solution:
	    def twoSum(self, nums: List[int], target: int) -> List[int]:
	        if nums is None or len(nums) == 0:
	            return []
	        map = set()
	        for i in nums:
	            if target - i in map:
	                return [target - i, i]
	            else:
	                map.add(i)i
	```
