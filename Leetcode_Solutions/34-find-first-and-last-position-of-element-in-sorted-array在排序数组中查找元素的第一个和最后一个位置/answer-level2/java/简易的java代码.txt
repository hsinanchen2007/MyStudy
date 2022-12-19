### 代码

```java
class Solution {
    public int[] searchRange(int[] nums,int target){
		// 数组已经基本有序，可以使用二分搜索，时间复杂度为O(logN)
		// 二分搜索思路不难，但是需要处理的细节比较多，这点是值得注意的
		int[] res = new int[2];
		Arrays.fill(res, -1);
		if(nums.length == 0){
			return res;
		}
		int left = 0;
		int right = nums.length-1;
		int mid = left + (right-left)/2;
		while(left < right && nums[mid]!=target){
			if(nums[mid]>target){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
			mid = left + (right-left)/2;
		}
		// 找到后需要向左右线性检查target的起始与终止位置
		int i = mid;
		int j = mid;
		while(i>=0 && nums[i] == target){
			res[0] = i;
			i--;
		}
		while(j<nums.length && nums[j] == target){
			res[1] = j;
			j++;
		}
		return res;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/26f65a40e5364cfb017f51e0b838ee7a34c0cd0bd5034a40eb40850813a680f4-1.png)
