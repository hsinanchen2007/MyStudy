# hashmap的方法
```
    //本题中因为数组中的值在其数组长度范围内，故可以用这个方法
    //将数组中的值作为hashmap中的key，判断key唯一
    HashMap<Integer, Integer> hashMap = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			if (!hashMap.containsKey(nums[i])) {//判断key是否存在
				hashMap.put(nums[i], i);
			} else
				return nums[i];//否则返回该数字
		}
		return -1;
```
# 数组排序的方法
```
    //因为只需要找任意一个重复数字，那么排序之后重复数字(如果有的话)肯定在一起
    	Arrays.sort(nums);//排序
		for (int i = 0; i < nums.length - 1; i++) {
			if (nums[i] == nums[i + 1])//比较
				return nums[i];
		}
		return -1;
```


