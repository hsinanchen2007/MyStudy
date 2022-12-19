### 解题思路
相较于三数，就是多一重循环，提高效率的点就在于剪枝，注意最大和最小的不符情况不同对待

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
      List<List<Integer>> result = new ArrayList<List<Integer>>();
		if(nums == null||nums.length<4) {
			return result;
		}
		Arrays.sort(nums);
		for(int i=0;i<nums.length-3;i++) {
			if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) { //最小值判断
				break;
			}
			if(i>0&&nums[i]==nums[i-1]||nums[i]+nums[nums.length-1]+nums[nums.length-2]+nums[nums.length-3]<target) { //相同跳过 最大值不符
				continue;
			}
			for(int j=i+1;j<nums.length-2;j++) {
				if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) { //最小判断
					break;
				}
				if(j>i+1&&nums[j]==nums[j-1]||nums[i]+nums[j]+nums[nums.length-1]+nums[nums.length-2]<target) {//相同跳过 最大值不符 
					continue;
				}
				int k=j+1;
				int m=nums.length-1;
				while(k<m) {
					if(nums[i]+nums[j]+nums[k]+nums[m]<target||(k>j+1&&nums[k]==nums[k-1])) {
						k++;
					}else if(nums[i]+nums[j]+nums[k]+nums[m]>target||(m<nums.length-1&&nums[m]==nums[m+1])) {
						m--;
					}else {
						List<Integer> lis = new ArrayList<Integer>();
						lis.add(nums[i]);
						lis.add(nums[j]);
						lis.add(nums[k]);
						lis.add(nums[m]);
						result.add(lis);
						k++;
						m--;
					}
				}
			}
		}
		return result;
    }
}
```