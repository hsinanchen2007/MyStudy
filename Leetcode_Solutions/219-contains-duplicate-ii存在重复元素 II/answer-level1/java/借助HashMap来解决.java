if (nums==null || nums.length==0) {
			return false;
		}
		Map<Integer, Integer> map=new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			if (map.containsKey(nums[i]) && i-map.get(nums[i])<=k) {
				return true;
			}else  {
				if (map.size()==k)
					map.remove(nums[i-k]);
				map.put(nums[i], i);
			} 
		}
		return false;

特别注意的是：map.remove(nums[i-k]);
1. 此处哈希表已满，需要移除头部元素，头部元素下标必然为i-k；
