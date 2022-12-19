class Solution {
    
	public static int[] intersect(int[] nums1, int[] nums2) {
		if(nums1.length > nums2.length) {
    		return getIntersect(nums2,nums1);
    	}else {
    		return getIntersect(nums1,nums2);
    	}
    }
    
    private static int[] getIntersect(int[] minNums,int[] maxNums) {
    	//最大数组用map
    	Map<Integer,Integer> map = new HashMap<Integer,Integer>(maxNums.length);
    	for(int num : maxNums) {
    		if(map.containsKey(num)) {
    			map.put(num, map.get(num)+1);
    		}else {
    			map.put(num, 1);
    		}
		}
		
    	//记录结果
    	List<Integer> list = new ArrayList<Integer>(minNums.length);
		for(int num : minNums) {
			if(map.containsKey(num)) {
				//数量大于零的才处理
				int count = map.get(num);
				if(count > 0) {
					list.add(num);
					map.put(num, count-1);
				}
			}
		}
		
		//如果没有结果直接返回
		if(list.isEmpty()) {
			return new int[] {};
		}
		
		//返回结果
		int result[] = new int[list.size()];
		for(int i = 0 ; i < list.size() ; i++) {
			result[i] = list.get(i);
		}
		return result;
    }
}