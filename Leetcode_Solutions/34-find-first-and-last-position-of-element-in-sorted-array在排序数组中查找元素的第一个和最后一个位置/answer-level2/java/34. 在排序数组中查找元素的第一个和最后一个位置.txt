### 解题思路
此处撰写解题思路
步骤1：首先通过二分查找法找出数组中是否含有目标值，如果没有，则返回[-1,-1]
步骤2：如果数组中含有目标值，则初始化开始位置和结束位置
步骤3：根据二分法查找到的下标，分别往两边延伸，分别判断是否是边界值
### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
      int[] targetIndex = {-1, -1};
        int len = nums.length;
        if (len == 0) {
			return targetIndex;
		}
        int index = -1;
        int lo = 0;
        int ho = len - 1;
        while (lo <= ho) {
        	int mid = (lo + ho) >>> 1;
        	if (target == nums[mid]) {
				index = mid;
				break;
			} else if (target < nums[mid]) {
				ho = mid - 1;
			} else if (target > nums[mid]) {
				lo = mid + 1;
			}
		}
        if (index == -1) {
			return targetIndex;
		}
        targetIndex[0] = index;
        targetIndex[1] = index;
        lo = 1;
        boolean min = true;
        boolean max = true;
        while (max || min) {
        	max = !max ? max : index + lo < len;
			if (max) {
				if (target < nums[index + lo]) {
					max = false;
					targetIndex[1] = index + lo - 1;
				} else if (index + lo == len - 1 && target == nums[index + lo]) {
					targetIndex[1] = index + lo;
				}
			}
			min = !min ? min : index - lo >= 0; 
			if (min) {
				if (target > nums[index - lo]) {
					min = false;
					targetIndex[0] = index - lo + 1;
				} else if (index - lo == 0 && target == nums[index - lo]) {
					targetIndex[0] = index - lo;
				}
			}
			lo++;
		}
        return targetIndex;
    }
}
```