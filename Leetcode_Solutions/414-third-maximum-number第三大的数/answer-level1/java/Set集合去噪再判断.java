```
public class LeetCode0414 {
	public int thirdMax(int[] nums) {
		int res = 0;
		HashSet<Integer> hs = new HashSet<Integer>();
		for (int i = 0; i < nums.length; i++) {
			hs.add(nums[i]);
		}

		int[] arr = new int[hs.size()];
		int index = 0;
		for (int i : hs) {
			arr[index++] = i;
		}
		Arrays.sort(arr);
		if (arr.length < 3) {
			res = arr[arr.length - 1];
		} else {
			res = arr[arr.length - 3];
		}

		return res;
	}
}
```
