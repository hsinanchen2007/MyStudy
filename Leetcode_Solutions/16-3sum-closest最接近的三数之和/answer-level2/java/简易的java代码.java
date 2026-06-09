### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums,int target){
		Arrays.sort(nums);
		int sum = 0;
		int diff = Integer.MAX_VALUE;
		for(int i=0;i<nums.length;i++){// 固定一个数nums[i]
			int newTarget = target-nums[i];
			int j=i+1;
			int k=nums.length-1;
			int currDiff = Integer.MAX_VALUE;
			while(j<nums.length && k>i && j<k){
				if(nums[j]+nums[k] == newTarget){
					return target;
				}else if(nums[j]+nums[k]<newTarget){
					currDiff = Math.abs(nums[j]+nums[k]-newTarget);
					if(currDiff < diff){
						diff = currDiff;
						sum = nums[i]+nums[j]+nums[k];
					}
					j++;
				}else{
					currDiff = Math.abs(nums[j]+nums[k]-newTarget);
					if(currDiff < diff){
						diff = currDiff;
						sum = nums[i]+nums[j]+nums[k];
					}
					k--;
				}
			}
		}
		return sum;
	}
}
```