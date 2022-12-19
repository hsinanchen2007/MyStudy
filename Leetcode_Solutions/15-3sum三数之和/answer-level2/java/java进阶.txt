### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
		
		if(nums==null || nums.length<3)
			return res;
		
		Arrays.sort(nums);
		
		for (int i = 0; i < nums.length; i++) {
			if(nums[i] > 0)
				break;
			
			if(i > 0 && nums[i] == nums[i-1]) continue;
			int j = i + 1;
			int k = nums.length - 1;
			
			while(j < k) {
				
				if(nums[i] + nums[j] + nums[k] < 0) {
					j ++;
				}else if(nums[i] + nums[j] + nums[k] == 0) {
					//等于0的情况中才需要去重
					List<Integer> list = new ArrayList<>();
					list.add(nums[i]);
					list.add(nums[j]);
					list.add(nums[k]);
					res.add(list);
					while(j<k && nums[j]==nums[j+1]) {
						j ++;
					}
					/*if(nums[j] == nums[j+1]) {
						j ++;
						continue;
					}
					if(nums[k] == nums[k-1]) {
						k --;
						continue;
					}*/
					while(j<k && nums[k]==nums[k-1]) {
						k --;
					}
					j ++;
					k --;
				}else {
					k --;
				}
			}
			
		}
		
		return res;
    }
}
```
![image.png](https://pic.leetcode-cn.com/6ab6bd70eba7373d1f28b6792a9753dd7786d46d1fdd173cc277bfd4463218a4-image.png)
