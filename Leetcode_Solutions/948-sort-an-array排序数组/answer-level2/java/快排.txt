### 解题思路
快排，每次选取第一个为中间值

### 代码

```java
class Solution {
	public int[] sortArray(int[] nums) {
        quicksort(nums, 0, nums.length - 1);
        return nums;
    }

	private void quicksort(int[] nums, int lo, int hi) {
		if(lo >= hi)return;
		int v = nums[lo];
		int low = lo + 1;
		int high = hi;
		while(true) {
			while(low <= high && nums[low] <= v) {
				low ++;
			}
			while(high >= low && nums[high] >= v) {
				high --;
			}
			if(low >= high) {
				break;
			}
			int t = nums[high];
			nums[high] = nums[low];
			nums[low] = t;
		}
		nums[lo] = nums[high];
		nums[high] = v;
		quicksort(nums, lo, high-1);
		quicksort(nums, high+1, hi);
	}

}
```