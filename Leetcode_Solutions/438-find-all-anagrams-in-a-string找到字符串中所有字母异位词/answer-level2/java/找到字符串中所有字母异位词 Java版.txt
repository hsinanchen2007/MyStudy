```java
public class Solution{
    /*
	 * 滑动窗口--双指针
	 * 	右移right指针,使得[left,right]窗口中包含所有的字符串p中的元素;
	 * 	如果当前窗口的长度刚好等于p的长度,说明找到了;
	 * 	否则从左边left判断当前字符是否存在于p中:
	 * 		如果不存在,left左移;
	 * 		如果存在,则mapS中对应的次数减1,同时若当前次数小于mapP中的次数,对应的match减一,然后left左移.
	 */
	public List<Integer> findAnagrams(String s, String p){
		List<Integer> list = new ArrayList<>();
		if(s == null || s.length() < p.length()) {
			return list;
		}
		Map<Character, Integer> mapS = new HashMap<>();
		Map<Character, Integer> mapP = new HashMap<>();
		//将字符串p中的元素和对应出现的次数添加进mapP中
		for(int i = 0; i < p.length(); i++) {
			mapP.put(p.charAt(i), mapP.getOrDefault(p.charAt(i), 0)+1);
		}
		int left = 0; //指向滑动窗口的左端
		int right = 0; //指向滑动窗口的右端
		int match = 0;
		while(right < s.length()) {
			char c = s.charAt(right);
			//如果当前字符存在于字符串p中
			if(mapP.containsKey(c)) {
				//就将该元素和对应的次数添加进mapS中
				mapS.put(c, mapS.getOrDefault(c, 0)+1);
				//若该元素的次数和p中出现的次数相同,则说明已经匹配完一个字符
				if((mapS.get(c)).equals(mapP.get(c))) {  //Integer对象之间比较要使用equals()
					match += 1;
				}
			}
			right++;
			//如果在当前窗口中,字符已经与p中的元素匹配完,则需要去除多余的元素
			while(match == mapP.size()) {
				//如果当前窗口的长度等于p的长度,说明证号匹配,则将左端索引left添加进list中
				if(right-left == p.length()) { 
					list.add(left); 
				}
				//否则判断左边left索引指向的元素
				char c2 = s.charAt(left);
				if(mapP.containsKey(c2)) { //如果mapP中包含该元素
					mapS.put(c2, mapS.get(c2)-1); //则将对应的次数减1
					 //如果当前窗口中出现的次数小于mapP中的,则匹配的个数match也要减1
					if(mapS.get(c2) < mapP.get(c2)) { 
						match--;
					}
				}
				left++; //left右移一位
			}
		}
		return list;
	}
}
```