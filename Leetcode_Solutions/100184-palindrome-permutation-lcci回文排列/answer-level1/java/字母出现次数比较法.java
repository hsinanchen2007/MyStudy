如果一个字符串为回文序列，则该字符串中不同字母出现的次数统计中最多有一个奇数。也就是如果该字符串长度为偶数，则字符串中不同字母出现的次数都应为偶数；如果该字符串长度为奇数，则字符串中只有一个字母的出现次数为奇数。
```
	public boolean canPermutePalindrome(String s) {
		Map<Character, Integer> map=new HashMap<Character, Integer>();
		for(char ss:s.toCharArray()) {
			map.put(ss, map.getOrDefault(ss, 0)+1);
		}
		int even=0;   //偶数
		int odd=0;   //奇数
		for(char key:map.keySet()) {
			if(map.get(key)%2==0) {
				even++;
			}else {
				odd++;
			}
		}
		if(odd>1) {
			return false;
		}else {
			return true;
		}
	}
```
