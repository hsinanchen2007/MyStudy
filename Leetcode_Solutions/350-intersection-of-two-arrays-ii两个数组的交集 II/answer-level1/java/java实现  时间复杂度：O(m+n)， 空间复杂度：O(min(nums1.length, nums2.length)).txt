class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
            if(nums1 == null || nums2 == null){
			return new int[0];
			
		}
		
		int len1 = nums1.length;
		int len2 = nums2.length;
		
		int[] res = new int[Math.min(len1, len2)];
		int index = 0;
        //key-数组的每个元素   val-出现的次数
		Map<Integer, Integer> map = new HashMap<>();
        
		for(int i=0; i<len1; i++){
            
			if(map.containsKey(nums1[i])){
				map.put(nums1[i], map.get(nums1[i]) + 1);
			}else{
				map.put(nums1[i], 1);
			}
			
		}
		
		for(int i=0; i<len2; i++){
			Integer val = map.get(nums2[i]);
            //每出现一个相同的，就将map数据集里的数量-1
			if(val != null && val  > 0){
				res[index++] = nums2[i];
				map.put(nums2[i], val-1);
			}
			
			
		}
		//这一步主要是讲res里默认值0的去掉
		int[] finalRes = new int[index];
		for(int i=0; i<index; i++){
			finalRes[i] = res[i];
			
		}
		return finalRes;
    }
}