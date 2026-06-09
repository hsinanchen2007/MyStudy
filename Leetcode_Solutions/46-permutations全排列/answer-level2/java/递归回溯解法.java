### 解题思路
这道题要注意的关键一点：需要申明一个boolean类型的数组boolean[] visited = new boolean[nums.length]
来记录当前的某个数字是否到达过，将visited加入道回溯中

### 代码

```java
class Solution {
    List<List<Integer>> result = new LinkedList<List<Integer>>();
	public List<List<Integer>> permute(int[] nums) {
		if(nums==null || nums.length<1)
			return result;
		
		List<Integer> list = new LinkedList<>();
		boolean[] visited = new boolean[nums.length];
		
		helper(nums, list, visited);
		return result;
	}
	
	private void helper(int[] nums, List<Integer> list, boolean[] visited) {
		if(list.size() >= nums.length) {
			result.add(new LinkedList<>(list));
			return;
		}
		
		for(int i = 0;i < nums.length;i ++) {
			if(visited[i]) continue;
			
			list.add(nums[i]);
			visited[i] = true;
			helper(nums, list, visited);
			visited[i] = false;
			list.remove(list.size()-1);
		}
	}
}
```
![image.png](https://pic.leetcode-cn.com/039e13fc35f18562e7a03b6d07444fc89285a8cbbab2758da70389fc552ea693-image.png)
