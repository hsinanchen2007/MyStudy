```java
public class Solution{
    /*
	 * 滑动窗口--双指针
	 * 	右移right指针,使得[left,right]窗口中包含所有的字符串t中的元素;
	 * 	如果当前窗口的长度刚好小于之前minLen,更新最短字串的开始索引start和长度;
	 * 	从左边left判断当前字符是否存在于p中:
	 * 		如果不存在,left左移;
	 * 		如果存在,则mapS中对应的次数减1,同时若当前次数小于mapT中的次数,对应的match减一,然后left左移.
	 * 	最后如果minLen还是初始值,说明没有找到返回"",否则返回[start,start+minLen]字串.
	 */
	public String minWindow(String s, String t) {
		if(s == null || t == null || s.length() < t.length()) {
			return "";
		}
		Map<Character,Integer> mapS = new HashMap<>();
		Map<Character,Integer> mapT = new HashMap<>();
		//将字符串t中的元素和对应出现的次数存储在mapT中
		for(int i = 0; i < t.length(); i++) {
			mapT.put(t.charAt(i), mapT.getOrDefault(t.charAt(i), 0)+1);
		}
		int left = 0; //指向满足条件的滑动窗口的左端
		int right = 0; //指向满足条件的滑动窗口的右端
		int match = 0;
		int minLen = Integer.MAX_VALUE; //存储最短字串的长度
		int start = 0; //字串开始的索引
		while(right < s.length()) {
			char c = s.charAt(right);
			//如果当前字符存在于字符串t中
			if(mapT.containsKey(c)) {
				//就将该元素和对应的次数添加进mapS中
				mapS.put(c, mapS.getOrDefault(c, 0)+1);
				//若该元素的次数和t中出现的次数相同,则说明已经匹配完一个字符
				if((mapS.get(c)).equals(mapT.get(c))) {  //Integer对象之间比较要使用equals()
					match++;
				}
			}
			right++;
			//如果在当前窗口中,字符已经与t中的元素匹配完,则需要去除多余的元素
			while(match == mapT.size()) {
				//如果当前窗口的长度小于当前最短字串,则更新start和minLen
				if(right-left < minLen) { 
					start = left;
					minLen = right-left;
				}
				//判断左边left索引指向的元素
				char c2 = s.charAt(left);
				if(mapT.containsKey(c2)) { //如果mapP中包含该元素
					mapS.put(c2, mapS.get(c2)-1); //则将对应的次数减1
					 //如果当前窗口中出现的次数小于mapP中的,则匹配的个数match也要减1
					if(mapS.get(c2) < mapT.get(c2)) { 
						match--;
					}
				}
				left++; //left右移一位
			}
		}
		return minLen == Integer.MAX_VALUE ? "":s.substring(start,start+minLen);
	}
}
```