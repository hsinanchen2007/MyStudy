内部类都用上了 哈哈 主要是排序 根据统计数量排序 然后拼接字符串
```
processing
         static class Item{
		 private char keys;
		 private int count; 
		 public Item(char key,int count) {
			 this.keys = key;
			 this.count = count;
		 }
	 }
	 public String frequencySort(String s) {
             if(s==null || s.length()==0)
                 return s;
	        char[] chars = s.toCharArray();
	        HashMap<Character, Integer> map = new HashMap<>();	    
	        for (char i : chars) {
	        	int count = 0;
	        	if(map.get(i)!=null) {
	        		count = map.get(i)+1;
	        	}else {
	        		count = 1;
	        	}
	        	 
	        	map.put(i, count);				
			}
	        List<Item>items = new ArrayList<>();
	        map.forEach((key,value)->{
	        	items.add(new Item(key, value));
	        });
	        
	        items.sort((o1,o2)->o2.count-o1.count);
	        StringBuilder sb = new StringBuilder();
	        items.forEach(o->{
	        	for(int i=0;i<o.count;i++)
	        		sb.append(o.keys);
	        });
	        String result = sb.toString();
	        return result;     
	             
	 }
```