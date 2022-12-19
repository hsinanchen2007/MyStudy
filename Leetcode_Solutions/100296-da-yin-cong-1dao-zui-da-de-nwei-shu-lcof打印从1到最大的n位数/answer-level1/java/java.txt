 public int[] printNumbers(int n) {
    	List<Integer> list = new ArrayList<Integer>();
    	int j =1;
    	while(String.valueOf(j).length()<=n) {
    		list.add(j);
    		j++;
    	}
    	return list.stream().mapToInt(Integer::valueOf).toArray();
    }