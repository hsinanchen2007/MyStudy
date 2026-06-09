### 解题思路
思路很简单，就是把target带进去重新排序，遍历输出target第一次出现的下标。
倒是如何实现想了一会儿。
代入用的是扩容后放在最后一位。
可能都比较基础，但是呢，体会到了解题的快乐！

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
    	int i = 0;
    	if (nums==null||nums.length==0) {
			return 0;
		}else {
			nums=Arrays.copyOf(nums, nums.length+1);
			nums[nums.length-1]=target;
			Arrays.sort(nums);
			for (i = 0; i < nums.length; i++) {
				if (nums[i]==target) {
					break;
				}
		}
		}
		return i;        
    }
}
```