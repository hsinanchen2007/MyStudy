### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public List<List<Integer>> permuteUnique(int[] nums) {
		List<List<Integer>> result = new LinkedList<List<Integer>>();
		
		List<Integer> list = new LinkedList<>();
		boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);
		helper(nums, result, list, visited);
		return result;
	}

	private void helper(int[] nums, List<List<Integer>> result, List<Integer> list, boolean[] visited) {
		if(list.size() == nums.length) {
			result.add(new LinkedList<>(list));
			return;
		}
		
		for (int i = 0; i < nums.length; i++) {
			if(visited[i]) continue;  
			
			if(i > 0 && !visited[i-1] && nums[i-1]==nums[i]) continue;
			
			list.add(nums[i]);
			visited[i] = true;
			helper(nums, result, list, visited);
			list.remove(list.size()-1);
			visited[i] = false;
		}
	}
}

```![image.png](https://pic.leetcode-cn.com/942b68fa4eabf07bf80b04c42aee8792402e5df47ac61a8350d94cf807458a1c-image.png)
