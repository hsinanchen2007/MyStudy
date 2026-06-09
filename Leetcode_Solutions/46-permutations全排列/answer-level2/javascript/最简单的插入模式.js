有2个人排成一排有2种站法，第3人插入这一排的左、中、右位置，然后循环插入第4人，第5人...
```javascript []
function T46(nums) {
	var left = [];
	if (nums.length == 0) return [[]];
	if (nums.length == 1) return [[nums[0]]];
	left.push([nums[0], nums[1]]);
	left.push([nums[1], nums[0]]);
	//从2位数字开始，遍历结果集，依次在数组下标位置插入后一位数字，这就是阶乘
	for (var size = 3; size <= nums.length; size++) {
		var right = [];
		//遍历较大的left集合，并把新值转移到right，结束后交换
		for (var i = 0; i < left.length; i++) {
			var list_i = left[i];
			for (var j = 0; j < size; j++) {
				var list_j = list_i.slice(0);
				//在原数组的下标位置插入数组第size个数
				list_j.splice(j, 0, nums[size - 1]);
				right.push(list_j);
			}
		}
		left = right;
	}
	return left;
}
```
```Java []
public List<List<Integer>> T46(int[] nums) {
	List<List<Integer>> left = new ArrayList<>();
	if (nums.length == 0) {
		left.add(new ArrayList<>());
		return left;
	}
	if (nums.length == 1) {
		left.add(Arrays.asList(nums[0]));
		return left;
	}
	left.add(Arrays.asList(nums[0], nums[1]));
	left.add(Arrays.asList(nums[1], nums[0]));
	//从2位数字开始，遍历结果集，依次在数组下标位置插入后一位数字，这就是阶乘
	for (int size = 3; size <= nums.length; size++) {
		List<List<Integer>> right = new ArrayList<>();
		//遍历较大的left集合，并把新值转移到right，结束后交换
		for (int i = 0; i < left.size(); i++) {
			List<Integer> list_i = left.get(i);
			for (int j = 0; j < size; j++) {
				List<Integer> list_j = new ArrayList<>(list_i);
				//在原数组的下标位置插入数组第size个数
				list_j.add(j, nums[size - 1]);
				right.add(list_j);
			}
		}
		left = right;
	}
	return left;
}
```
