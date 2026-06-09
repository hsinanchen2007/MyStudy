### 解题思路
利用hash表储存已遍历的元素，在hash中提前移除已不符合要求的元素

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet(nums.length);

		//  防止 K > nums.length 越界
		k = k>nums.length?nums.length:k;
		// 处理 k 之前的
		for(int i=0;i<k;i++) {
			if(!set.add(nums[i])) {
				return true;
			}
		}
		//  处理 K 之后的
		for(int i=k; i<nums.length; i++) {
			if(!set.add(nums[i])) {
				return true;
			}
			set.remove(nums[i-k]);
		}
		
		return false;
    }
}
```