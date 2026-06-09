   public static String minNumber(int[] nums) {
    
    	 ArrayList<String> list = new ArrayList<String>();
    	 for(int i:nums) {
    		 list.add(String.valueOf(i));
    	 }
    	 StringBuffer sb = new StringBuffer();
        //list.sort((o1,o2) ->(o2+o1).compareTo(o1,o2));//这是升序排
    	 list.sort((o1,o2) ->(o1+o2).compareTo(o2+o1));//这是降序排

    	 System.out.println(list);
    	for(String s:list) {
    		sb.append(s);
    	}
    	System.out.println(list);
    	 return  sb.toString();
    }

