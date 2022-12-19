这个是一篇，脑子都不用转就能看懂的代码，没有if else switch。
```
    public int romanToInt(String s) {
    	s = s.replace("IV", "a")
    		.replace("IX", "b")
    		.replace("XL", "c")
    		.replace("XC", "d")
    		.replace("CD", "e")
    		.replace("CM", "f");
    	Map<Character, Integer> map = new HashMap<Character, Integer>();
    	map.put('I', 1);
    	map.put('V', 5);
    	map.put('X', 10);
    	map.put('L', 50);
    	map.put('C', 100);
    	map.put('D', 500);
    	map.put('M', 1000);
    	map.put('a', 4);
    	map.put('b', 9);
    	map.put('c', 40);
    	map.put('d', 90);
    	map.put('e', 400);
    	map.put('f', 900);
    	int count = 0;
    	for (int index = 0; index < s.length(); index++) {
    		count += map.get(s.charAt(index));
    	}
    	return count;
    }
```
