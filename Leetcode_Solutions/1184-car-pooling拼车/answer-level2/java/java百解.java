### 解题思路
直接创建数组缓存每个车站的人数变动，检索时判断和值是否超限即可

### 代码

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] nums = new int[1001];
		for (int i = 0; i < trips.length; i++) {
			int[] is = trips[i];
			nums[is[1]] = nums[is[1]] + is[0];
			nums[is[2]] = nums[is[2]] - is[0];
		}
		int count = 0;
		for (int i : nums) {
			count += i;
			if (count > capacity) {
				return false;
			}
		}
		return true;
    }
}
```