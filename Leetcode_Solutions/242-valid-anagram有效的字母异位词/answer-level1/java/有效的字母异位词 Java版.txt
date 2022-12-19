```java
public class Solution{
    /*
	 * 先将两个字符串转为字符数组
	 * 对两个字符数组分别排序
	 * 如果是字母异位词，那么这两个字符数组里的元素和顺序应该完全相等，使用Arrays.equals(str1,str2)比较
	 * 	注意，str1和str2是字符数组，不能使用str1.equals(str2)比较
	 */
	public static boolean isAnagramSort(String s, String t) {
		if(s.length() != t.length()) return false;
		char[] str1 = s.toCharArray();
		char[] str2 = t.toCharArray();
		//对两个字符数组排序
		Arrays.sort(str1);
		Arrays.sort(str2);
		return Arrays.equals(str1, str2); //如果相同，则说明是字母异位词
	}
	
	/*
	 * 使用一个长度为26的数组存储对应字符串s中字符出现的次数
	 * 遍历字符串t，对应的字符的次数减一，如果小于0，则直接返回false；
	 * 否则，如果没有返回，则判断两个字符串的长度是否相等
	 */
	public static boolean isAnagramArray(String s, String t) {
		int[] chs = new int[26]; //存放二十六个字母对应的出现的次数
		//chs中存储字符串s中的元素和对应的次数
		for(int i = 0; i < s.length(); i++) {
			chs[s.charAt(i) - 'a']++;
		}
		
		//遍历字符串t中的每一个字符
		for(int i = 0; i < t.length(); i++) {
			//如果对应的字母在减一之后的次数小于0，则直接返回false
			if(--chs[t.charAt(i)-'a'] < 0) {
				return false;
			}
		}
		//如果都遍历完后会还没有返回，则如果两个字符串的长度相等，则返回true，否则返回false
		return s.length() == t.length(); 
	}
	
	/*
	 * 使用HashMap存储s的字符和对应出现的次数
	 * 遍历t中的每一个字符，如果map中不包含这个字符，或者map中对应的次数小于等于0，则直接返回false
	 */
	public static boolean isAnagramHashMap(String s, String t) {
		if(s == null || t == null) return false;
		if(s.length() == 0 && t.length() == 0) return true;
		if(s.length() == 0 || t.length() == 0 || s.length() != t.length()) return false;
		Map<Character,Integer> map = new HashMap<>();
		//将每个字符及出现的次数存于HashMap map中
		for(int i = 0; i < s.length(); i++) {
			map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0)+1);
		}
		//遍历字符串t中的每一个字符，如果map中包含该字符，并且次数大于0，则将对应的次数减一，继续判断下一个字符
		for(int i = 0; i < t.length(); i++) {
			if(map.containsKey(t.charAt(i)) && map.get(t.charAt(i))>0) {
				map.put(t.charAt(i), map.get(t.charAt(i))-1);
			}else {  //否则，直接返回false
				return false;
			}
		}
		return true;
	}
}
```