利用回溯的方法，思路是：

1. 遍历数组中的值，如果nums[i] < target , 尝试把nums[i]作为一个加数，把目标值减去nums[i]，下一次递归从i+1开始遍历数组寻找下一个加数
2. 如果target=0，说明找到了一组加数
3. 否则把上一个加数从list中去掉

去重：需要先对数组进行排序，每次递归寻找的是一个位置的加数值，同一个位置不能使用相同的加数值,
```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
	
	public List<List<Integer>> combinationSum2(int[] candidates, int target) {
		    if(candidates.length == 0)
		    	return ans;
            Arrays.sort(candidates);
		    helper(candidates, 0, target, new ArrayList<>());
		 
		    return ans;		        
	}
	
	private void helper(int[] nums, int l, int target, List<Integer> list) {
		
		if(target == 0) {
			ans.add(new ArrayList<>(list)); //存入的是复制的list对象，避免递归时修改list也修改了ans中的解
			//list = new ArrayList<>();
			return;
		}
		for(int i=l;i<nums.length;i++) {
            //[10,1,2,7,6,1,5] => [1,1,2,5,6,7,10]  target=8
			//假设现在寻找第一个加数，nums[0] = 1 ,第一个加数是位置0的1，然后可以找到 [1,1,6] [1,7]，最后递归回归到i=0，即寻找第一个加数的递归函数
			//尝试nums[1]作为第一个加数, 此时发现nums[1] = nums[0] ,那么递归下去一定可以找到重复的解[1,7], 因此跳过nums[1]
			// i > l的目的是 确保不是第一次使用这个加数，如果不保证i > l, 那么[1,1,6]这样的解就会丢失
			if(i > l && nums[i] == nums[i-1]) 
				continue;
			if(target - nums[i] >= 0) {
				list.add(nums[i]);
				helper(nums, i+1, target - nums[i], list);
				if(list.size() > 0)
					list.remove(list.size() - 1); //没有找到一组解
			}
			
		}
	}
}
```

