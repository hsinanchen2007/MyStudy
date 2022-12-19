```
class Solution {
    public int balancedStringSplit(String s) {
        int count=0;
        char[] chars=s.toCharArray();
        Map<Character, Integer> map=new HashMap<Character, Integer>();
        for (int i = 0; i < chars.length; i++) {
        	map.put(chars[i], map.getOrDefault(chars[i], 0)+1);
			if (map.getOrDefault('R',0).intValue()==map.getOrDefault('L',0)) {
				count++;
				map.clear();
			}
		}
        return count;
    }
}
```
