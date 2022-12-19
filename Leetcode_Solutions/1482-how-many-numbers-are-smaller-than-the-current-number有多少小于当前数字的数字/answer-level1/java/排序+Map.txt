1、先对数组排序；
2、采用map记录，各个值对应的 下标值；
3、对原数组每个值，查询元素对应的下标值返回；    

public int[] smallerNumbersThanCurrent(int[] nums) {
    int[] sortNums = Arrays.stream(nums).sorted().toArray();

    int len = nums.length;
    Map<Integer, Integer> map = new HashMap<>();
    for(int i = 0; i < len; i++) {
        map.putIfAbsent(sortNums[i], i);
    }

    int[] result = new int[len];
    for(int i = 0; i < len; i++) {
        result[i] = map.get(nums[i]);
    }

    return result;
}