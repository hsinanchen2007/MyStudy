public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();		
		for (int i = 0; i < nums.length; i ++) {
			if (hashMap.get(nums[i]) == null) {
				hashMap.put(nums[i], nums[i]);				
			}
			else {
				hashMap.remove(nums[i]);
			}			
		}
		Iterator iter = hashMap.keySet().iterator();
		Integer key;
		Integer value = null ;
		while (iter.hasNext()) {
			key = (Integer) iter.next();
			value = (Integer) hashMap.get(key);						
		}
		return value;
    }

	11 ms	39.3 MB