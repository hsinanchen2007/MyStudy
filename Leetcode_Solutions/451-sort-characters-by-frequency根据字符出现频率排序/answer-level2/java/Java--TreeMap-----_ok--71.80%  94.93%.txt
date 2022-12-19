```
class Solution {
	private Map<Character,Integer>map=new TreeMap<Character,Integer>();
    public String frequencySort(String s) {
    	for (int i=0;i<s.length();i++){
	            char c = s.charAt(i);
	            map.put(c,map.get(c)==null?1:map.get(c)+1);
	        }
    	List<Map.Entry<Character, Integer>>list=new ArrayList<Map.Entry<Character, Integer>>(map.entrySet());
    	Collections.sort(list, new Comparator<Map.Entry<Character, Integer>>(){

			@Override
			public int compare(Map.Entry<Character, Integer> arg0, Map.Entry<Character, Integer> arg1) {
				return arg1.getValue().compareTo(arg0.getValue());
			}
    		
    	});
    	StringBuilder stringBuilder=new StringBuilder();
    	for(Map.Entry<Character, Integer> var:list)
    	{
    		for(int i=0;i<var.getValue();++i)
    		{
    			stringBuilder.append(var.getKey());
    		}
    	}
		return stringBuilder.toString();     
    }
}