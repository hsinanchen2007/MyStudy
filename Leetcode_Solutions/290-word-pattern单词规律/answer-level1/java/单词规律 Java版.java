```java
public class Solution{
/*
	 * 使用HashMap映射 pattern中字符(key)和str中单词(value)的关系：
	 * 	如果pattern和str的长度不同，直接返回false
	 * 	如果当前key存在于map，但是value值不等于当前的单词，返回false；
	 * 	如果当前key不存在于map，但是当前单词存在于map的value中，返回false
	 */
	public static boolean wordPattern(String pattern, String str) {
		String[] s = str.split(" ");
		if(pattern.length() != s.length) return false; //两个长度不等，直接返回false
		Map<Character,String> map = new HashMap<>();
		for(int i = 0; i < pattern.length(); i++) {
			if(!map.containsKey(pattern.charAt(i))){ //如果map的Key中不包含pattern中的字符
				if(map.containsValue(s[i])) { //但是Value中包含s中的单词
					return false;  
				}
				map.put(pattern.charAt(i), s[i]); //map中都不包含，则将映射关系存入map中
			}else { //如果map的Key中包含pattern中的字符
				if(!map.get(pattern.charAt(i)).equals(s[i])) { //但是pattern中字符对应的Value即映射的单词不等于当前的单词
					return false;
				}
			}
		}
		return true;
	}
}
```