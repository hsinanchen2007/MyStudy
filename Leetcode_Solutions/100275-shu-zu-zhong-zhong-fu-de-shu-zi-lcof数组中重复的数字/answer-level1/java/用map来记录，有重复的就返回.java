### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
		HashMap map = new HashMap<Integer,Integer>();
		for(int i=0;i<nums.length;i++){
			Object s =  map.get(nums[i]);
			if(s==null){
				map.put(nums[i],nums[i]);
			}else{
				return nums[i];
			}
		}
        return 0;
    }
}
```