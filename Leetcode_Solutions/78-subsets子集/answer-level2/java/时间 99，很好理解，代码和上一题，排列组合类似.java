```
public static List<List<Integer>> subsets(int[] nums) {

		List<List<Integer>> list = new ArrayList<>();

		List<Integer> tempData = new ArrayList<>();
		List<Integer> tempData1 = new ArrayList<>();
		for (int i = 0; i < nums.length; i++)
			tempData1.add(nums[i]);

		list.add(tempData);
		list.add(tempData1);
		for (int i = 1; i < nums.length; i++) {
			combine(nums, i, list);
		}

		return list;

	}

	public static List<List<Integer>> combine(int[] nums, int k, List<List<Integer>> list) {

		List<Integer> tempData = new ArrayList<>();
		doHelper(0, k, nums, list, tempData, 0);
		return list;
	}

	public static void doHelper(int cursor, int k, int[] nums, List<List<Integer>> list, List<Integer> tempData,
			int num) {
		if (num == k) {
			list.add(new ArrayList<>(tempData));
		} else {
			for (int i = cursor; i <= nums.length - k + num; i++) {
				tempData.add(nums[i]);
				doHelper(i + 1, k, nums, list, tempData, num + 1);
				tempData.remove(tempData.size() - 1);
			}
		}

	}

```
