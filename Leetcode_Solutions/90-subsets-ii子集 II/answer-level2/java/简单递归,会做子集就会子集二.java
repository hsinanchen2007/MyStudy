### 解题思路
与[子集](https://leetcode-cn.com/problems/subsets/)那个题思路大致相同,
多了先排序,然后数组第一个进入递归,后面跳过即可!

### 代码

```java
class Solution {
	List<List<Integer>> res = new ArrayList<List<Integer>>();
	int[] nums;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
    	this.nums = nums;
    	Arrays.parallelSort(nums);
    	res.add(new ArrayList<Integer>());
    	for(int i=0 ; i<nums.length ; i++) {
    		helper(new ArrayList<Integer>(), i);
    		while(i<nums.length-1 && nums[i+1]==nums[i])i++;
    	}
    	return res;
    }
    
    void helper(List<Integer> list , int n) {
    	
    	if(n==nums.length) return;
    	list.add(nums[n]);
    	res.add(list);
    	for(int i=n+1 ;i<nums.length ;i++) {
    			
        		helper(new ArrayList<Integer>(list),i);
        		while(i<nums.length-1 && nums[i+1]==nums[i])i++;
    	}
    	
    }
}
```