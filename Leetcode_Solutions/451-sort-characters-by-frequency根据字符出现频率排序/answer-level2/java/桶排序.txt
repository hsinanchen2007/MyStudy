算法思想：桶排序，将字符的出现次数作为数组的下标，将出现的字符作为数组的内容。根据坐标进行降序，然后把坐标和对应的内容“相乘”后存放在字符串中，返回遍历后的结果。
```
public static String frequencySort(String s) {
		 HashMap<Character,Integer> map = new HashMap<Character,Integer>();
		 for(int i=0; i< s.length();i++)
		 {
			 char key = s.charAt(i);
			 if(!map.containsKey(key))
				 map.put(key, 1);
			 else
				 map.put(key, (int)map.get(key)+1);
		 }
		 List[] al = new ArrayList[s.length()+1];
		 for (Object key : map.keySet()) {
			int value = (int) map.get(key);
			if(al[value] == null)
				al[value] = new ArrayList<Character>();
			al[value].add(key);
		}
		StringBuilder result = new StringBuilder();
		 for(int i = al.length-1 ;i>0 ; i--)
		 {
			 if(al[i] != null)
			 {	
				 for(int j = 0 ;j <al[i].size();j++)
				 {
					 for(int z = 0 ;z < i ;z++)
						 result.append(al[i].get(j));
				 }
			 } 
		 }
	      return result.toString();  
	 }
```