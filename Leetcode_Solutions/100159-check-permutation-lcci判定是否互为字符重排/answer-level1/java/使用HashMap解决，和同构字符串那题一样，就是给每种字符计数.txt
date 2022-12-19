```
public boolean CheckPermutation(String s1, String s2) {
    Map<Character, Integer> map1 = new HashMap<>();
	for (int i = 0; i < s1.length(); i++) {
		map1.put(s1.charAt(i), map1.getOrDefault(s1.charAt(i), 0)+1);
	}
	Map<Character, Integer> map2 = new HashMap<>();
	for (int i = 0; i < s2.length(); i++) {
		map2.put(s2.charAt(i), map2.getOrDefault(s2.charAt(i), 0)+1);
	}
	return map1.equals(map2);    
    }
```
