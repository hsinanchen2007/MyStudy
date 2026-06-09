```java
class Solution {
    public String getKey(String str){
        char[] chars = new char[str.length()];
        for (int i = 0; i < chars.length; i++) {
			chars[i] = str.charAt(i);
		}
		
		int m = 'a' - chars[0];
		int n;
		for (int i = 0; i < chars.length; i++) {
	        n = chars[i]+m;
			chars[i] = (char)(n>96?n:(n+26));
	    }
        
        return String.valueOf(chars);
    }
    
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> map = new HashMap<>();
        String key = null;
        List<String> ls = null;
        for(String str : strings){
            key = getKey(str);
            if(map.containsKey(key)){
                map.get(key).add(str);
            } else {
                ls = new ArrayList<>();
                ls.add(str);
                map.put(key, ls);
            }
        }
        
        List<List<String>> res = new ArrayList<>();
        for(Map.Entry<String, List<String>> entry : map.entrySet()){
            res.add(entry.getValue());
        }
        return res;
    }
}
```
