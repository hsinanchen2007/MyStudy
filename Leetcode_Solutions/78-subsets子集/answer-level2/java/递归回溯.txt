### 解题思路
有一句代码很重要：
**result.add(new LinkedList<Integer>(list));**

*假如写成：result.add(list);* 那么输出result一直为空[]集合
我也不知道为什么

### 代码

```java
class Solution {
    List<List<Integer>> result = new LinkedList<List<Integer>>();
	
	public List<List<Integer>> subsets(int[] nums) {
		
		if(nums==null || nums.length < 1)
			return result;
		
		List<Integer> list = new LinkedList<>();
		result.add(list);
		
		helper(nums, 0, list);
		return result;
	}
	
	private void helper(int[] nums, int index, List<Integer> list) {
		if(index >= nums.length) {
//			result.add(new LinkedList<>(list));
			return;
		}
		
//		result.add(new ArrayList<Integer>());
		//放[1]
		list.add(nums[index]);
		result.add(new LinkedList<Integer>(list));
		helper(nums, index+1, list);
		//不放[1]
		list.remove(list.size()-1);
		helper(nums, index+1, list);
		
	}
}
```
![image.png](https://pic.leetcode-cn.com/b92ef3cf8002d842bbe21a1a2627a9e1f44d2d0e2fe5f50bb74613b923b15084-image.png)
