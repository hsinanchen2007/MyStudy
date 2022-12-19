### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates,int target){
		// 回溯法
		List<List<Integer>> res = new ArrayList<>();
		List<Integer> curr = new ArrayList<>();
		Arrays.sort(candidates);
		backtrack(res,curr,candidates,target,0);
		return res;
	}
	
	public void backtrack(List<List<Integer>> res,List<Integer> curr,int[] candidates,int target,int index){
		// 参数index用于避免重复
		if(target == 0){
			res.add(new ArrayList<>(curr));
			return;// 将控制权交给上层，使其执行回退操作
		}
		for(int i=index;i<candidates.length;i++){
			if(candidates[i] <= target){
				curr.add(candidates[i]);
				target -= candidates[i];	
				backtrack(res,curr,candidates,target,i);
				// 回退
				target += candidates[i];
				curr.remove(curr.size()-1);
			}else{//candidates[i] > target
				return;// 把控制权交回上一层，使其执行回退操作
			}
		}
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/f1f119cb7eb600f2e0673339febbb1d9b53c3359dddfdf1da1ff6ad759b866a6-1.png)
