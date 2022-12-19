 所谓同构就跟小学生组词一样，例如abb、aabb、abab这些种类型的。
 思路就是判断两个字符串对应位置的字母第一次出现在字符串中位置是否相同，
 例如:egg 每个字母第一次出现的位置是 0 1 1，add同样也是0 1 1,所以这两个字符串是同构的。

```
class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<String, Integer> mapS = new HashMap<String, Integer>();
		Map<String, Integer> mapT = new HashMap<String, Integer>();

		int length = s.length();
		for (int i = 0; i < length; i++) {
			char key = s.charAt(i);
			if (!mapS.containsKey(String.valueOf(key))) {
				mapS.put(String.valueOf(key), i);
			}
			key = t.charAt(i);
			if (!mapT.containsKey(String.valueOf(key))) {
				mapT.put(String.valueOf(key), i);
			}
		}
		for (int i = 0; i < length; i++) {
			char charS = s.charAt(i);
			char charT = t.charAt(i);
			if (mapS.get(String.valueOf(charS)).compareTo(mapT.get(String.valueOf(charT))) == 0) {
				continue;
			} else {
				return false;
			}
		}

		return true;
    }
}
```
