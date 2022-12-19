```java
public class Solution{
    /*
	 * 对比两个字符串对应位置的字符在字符串内第一次出现的位置。
	 */
	public static boolean isIsomorphic(String s, String t) {
		for(int i = 0; i < s.length(); i++) {
			if(s.indexOf(s.charAt(i)) != t.indexOf(t.charAt(i))) {
				return false;
			}
		}
		return true;
	}
	
	/*
	 * 使用两个HashMap相互映射
	 */
	public static boolean isIsomorphicHashMap(String s, String t) {
		Map<Character,Character> mapS = new HashMap<>(); //存储s中字符和t中字符的映射
		Map<Character,Character> mapT = new HashMap<>(); //存储t中字符和s中字符的映射
		for(int i = 0; i < s.length();i++) {
			char ss = s.charAt(i);
			char tt = t.charAt(i);
			if(mapS.containsKey(ss)) { //如果mapS中共包含s中的字符
				if(mapS.get(ss) != tt) { //但是映射的t中字符不等于t中字符
					return false;
				}
			}else if(mapT.containsKey(tt)) { //如果mapT中共包含t中的字符
				if(mapT.get(tt)!=ss) { //但是映射的s中字符不等于s中字符
					return false;
				}
			}else {  //将映射关系存入mapS和mapT
				mapS.put(ss, tt); 
				mapT.put(tt,ss);
			}
		}
		return true;
	}
}
```