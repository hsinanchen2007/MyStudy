思路很简单，对字符串从前往后遍历一遍，将当前字符代表的数字加至结果中，若当前字符大于前一个字符，意味着前一个字符应该是减法（**所以减去2倍**，再加上当前字符代表的数字）
```

public int romanToInt(String s) {
	HashMap<Character, Integer> map = new HashMap<>();
	map.put('I', 1);
	map.put('V', 5);
	map.put('X', 10);
	map.put('L', 50);
	map.put('C', 100);
	map.put('D', 500);
	map.put('M', 1000);
        int len = s.length();
        int res = 0;
        int tem0 = 1000;
        int tem1 = 0;
        for (int i=0; i<len; i++) {
            tem1 = map.get(s.charAt(i));
            if (tem0 >= tem1) res = res + tem1;
            else res = res + tem1 - 2 * tem0;
            tem0 = tem1;
        }        		
        return res;
    }
```
