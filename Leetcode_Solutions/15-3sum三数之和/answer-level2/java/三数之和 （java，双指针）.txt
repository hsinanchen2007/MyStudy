### 解题思路
使用双指针进行查找，然后移动时相同的数跳过

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
		List<Integer> m;
		int low,high;
		if(nums.length==0 || nums.length<=2) return list;
		Arrays.sort(nums);
		for(int i=0;i<nums.length;i++){
			if(i>=1 && nums[i]==nums[i-1]) continue;
			low = i+1;
			high = nums.length-1;
			m = new ArrayList<>();
			while(low<high){
				if(nums[low]+nums[high]>(-nums[i])) high--;
				else if(nums[low]+nums[high]<(-nums[i])) low++;
				else if(nums[low]+nums[high]==(-nums[i])){
					m = Arrays.asList(nums[i],nums[low],nums[high]);
					list.add(m);
					while(low<high ) 
                        if(nums[high]==nums[high-1]) high--;
                        else{high--;break;} 
				}
			}
        }
        return list;
    }
}
```