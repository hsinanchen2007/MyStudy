### 解题思路

因为这个问题没有顺序的问题，至于数量的问题，可以利用HashMap，把字符串都放到HashMap中，然后判断两个HashMap是否一致，就可以求解。

这一题取自“字符串中的第一个唯一字符”的灵感，感觉很相似。

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
    
		HashMap map1 = new HashMap();
		HashMap map2 = new HashMap();

		for (int i = 0; i < s.length(); i++) {
			if (map1.containsKey(s.charAt(i))) {
				map1.put(s.charAt(i), (int)map1.get(s.charAt(i)) + 1);
			}else {
				map1.put(s.charAt(i), 1);
			}
		}
		
		for (int j = 0; j < t.length(); j++) {
			if (map2.containsKey(t.charAt(j))) {
				map2.put(t.charAt(j), (int)map2.get(t.charAt(j))+ 1);
			}else {
				map2.put(t.charAt(j), 1);
			}
		}
		
		return map1.equals(map2);


    }
}
```