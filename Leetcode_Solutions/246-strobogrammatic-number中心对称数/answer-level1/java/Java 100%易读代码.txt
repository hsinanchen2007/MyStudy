

```
public boolean isStrobogrammatic(String num) {
		HashMap<Character, Character> map = getMap();
		int n = num.length();
		int i = 0, j = n - 1;
		char c1, c2;
		while (i <= j) {
			c1 = num.charAt(i);
			if (!map.containsKey(c1)) {
				return false;
			}
			c1 = map.get(c1);
			c2 = num.charAt(j);
			if (c1 != c2) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	HashMap<Character, Character> getMap() {
		HashMap<Character, Character> map = new HashMap<Character, Character>();
		map.put('0', '0');
		map.put('1', '1');
		map.put('6', '9');
		map.put('8', '8');
		map.put('9', '6');
		return map;
	}
```
