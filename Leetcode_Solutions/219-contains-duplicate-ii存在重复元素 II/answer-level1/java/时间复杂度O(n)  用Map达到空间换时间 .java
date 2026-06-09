### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int i=0;i<nums.length;i++) {
			if(map.containsKey(nums[i])) {
				if(i-map.get(nums[i])<=k) {
					return true;
				}
			}
			map.put(nums[i], i);
		}
        return false;
    }
}
```