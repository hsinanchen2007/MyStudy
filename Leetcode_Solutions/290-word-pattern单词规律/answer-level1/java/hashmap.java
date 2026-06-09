```
class Solution {
	public boolean wordPattern(String pattern, String str) {
		Map<Character, String> mp = new HashMap<Character, String>();
		String[] temp = str.split(" "); //将字符串分割
		if (pattern.length() != temp.length) //长度不等直接错
			return false;
		for (int i = 0; i < temp.length; i++) {
			char b = pattern.charAt(i); //得到每个字符
			if (mp.containsKey(b)) { //检验该key是否出现过
				if (mp.get(b).compareTo(temp[i]) != 0) { //出现过判断和之前保存的value是否相等 不相等错 相等继续判断
//					System.out.println(mp.get(b));
//					System.out.println(mp.get(b).length());
//					System.out.println(temp[i]);
//					System.out.println(temp[i].length());
					return false;
				}
			} else { //key未出现过 检测该value是否出现过（验证唯一对应关系）
				if(mp.values().contains(temp[i]))
					return false;
				mp.put(b, temp[i]);
			}

		}
		return true;
	}
}
```
