```
class Solution {
    public int numJewelsInStones(String J, String S) {
	int num = 0;
	Map<Character, String> map = new HashMap<>();
	for (int i = 0; i < J.length(); i++){
        map.put(J.charAt(i), null);
    }
	for (int j = 0; j < S.length(); j++){
		if (map.containsKey(S.charAt(j))){
			num++;
		}
	}
return num;
}
}
```