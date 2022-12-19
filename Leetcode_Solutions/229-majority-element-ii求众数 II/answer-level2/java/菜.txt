public List<Integer> majorityElement(int[] nums) {
       Map<Integer,Integer> map = new HashMap<Integer, Integer>();
       for(int i: nums) {
    	   map.put(i, map.getOrDefault(i, 0)+1);
       }
       List<Integer> list =new ArrayList<Integer>();
       int l = nums.length/3;
       for(int i:map.keySet()) {
    	   if(map.get(i)>l) {
    		   list.add(i);
    	   }
       }
       return list;
    }