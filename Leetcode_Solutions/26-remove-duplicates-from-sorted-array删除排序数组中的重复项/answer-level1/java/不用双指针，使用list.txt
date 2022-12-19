```
public int removeDuplicates(int[] nums) {
		if(nums==null)return 0;
		if(nums.length==0)return 0;
		List<Integer> a=new ArrayList<>();
		if(nums.length!=0)a.add(nums[0]);
		for(int i=1;i<nums.length;i++){
			if(nums[i]==nums[i-1])continue;
			else{
				a.add(nums[i]);
			}
		}
		for(int j=0;j<a.size();j++){
			nums[j]=a.get(j);
		}
		return a.size();
	}
```
运行时间慢了，但是占用内存还不错。所以就分享上来了。其实和双指针是一样的思路，
![2019-11-12_143400.jpg](https://pic.leetcode-cn.com/a0252240f946e45d09189f6a15f7fb2e907e46cdc95c0cd8476957a6781e403f-2019-11-12_143400.jpg)

