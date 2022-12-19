1. 对于这道题，首先分析就是看数组中有没有大小完全相同的四组的和，使用回溯算法遍历所有的情况，因为数组的大小不会超过15，数据规模比较小

2. 首先做一个判断，如果这些火柴压根没有，或者火柴长度的和都不能整除4，返回false

3. 然后就是考虑如何回溯，首先要设置一个isVisit数组，它的目的主要就是如果得到了一组可以组成边的集合，那这组集合中的每个值在下一组中都是不能使用的，将它们设为true，去找下一组满足条件的集合，然后设一个表示当前和的cur，还有一个目标数target(sum/4),还有一个index，目的是为了让当前的元素只和后面的元素去结合，还有一个记录当前满足组数的group，这里还要对数组进行排序，因为如果有相同的元素，它的前一个没有访问过，证明它的前一个是不满足要求的，那么它也一样，就直接continue

4. 写回溯的函数，递归的终止条件是满足的组数达到4，返回true，如果当前有了一组满足要求的，继续递归地去看下一组，另外就是一个剪枝，当当前的这一组的值大于target，那整个都不能构成正方形，返回false，还有就是上面说的，当有相同的元素时，continue

```
class Solution {
    private boolean canform(int[]nums,int index,int cur,int target,boolean[]isVisit,int judge) {
    	//如果有了4组和相同的值，返回true
    	if(judge==4) return true;
    	//如果此时有了一个等于目标值的和，去继续遍历下一个
    	if(cur==target) return canform(nums,0, 0, target, isVisit, judge+1);
        //如果当前的这一轮中有一个和大于target，那么这一轮就不能构成目标数
    	if(cur>target) return false;
    	for(int i=index;i<nums.length;i++) {
    		if(i>1&&nums[i]==nums[i-1]&&!isVisit[i-1]) continue;
    		if(!isVisit[i]) {
    		cur+=nums[i];
    		isVisit[i]=true;
    		if(canform(nums,i+1, cur, target, isVisit, judge)) {
    			return true;
    		}
    		cur-=nums[i];
    		isVisit[i]=false;
    		}
    	}
    	return false;
    }
	public boolean makesquare(int[] nums) {
		// 如果火柴数小于4或者总的长度不能整除4，返回false
		if (nums.length < 4)
			return false;
		int sum = 0;
		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
		}
		if (sum % 4 != 0)
			return false;
		//设置一个布尔类型的数组，来看当前的数字是否访问过
		boolean[] isVisit=new boolean[nums.length];
		//设置一个数字，来看当前组成了几组目标数，如果为4，返回true
		int judge=1;
		//对数组进行排序
		Arrays.sort(nums);
		return canform(nums,0,0,sum/4,isVisit,judge);
		
	}
}
```



