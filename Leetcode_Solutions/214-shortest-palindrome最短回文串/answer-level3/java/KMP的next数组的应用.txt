    
    public static String shortestPalindrome2(String s) {
		if(s.length() <= 1) {
			return s;
		}
		StringBuilder sb = new StringBuilder(s);
		String str = s + "#" + sb.reverse() + "@";
		int[] next = new int[str.length()];
		next[0] = -1;  // 前两个人为规定，第一个字符前面没有字符串，更别提前后缀
		next[1] = 0;   // 第二个字符前面就一个字符构成字符串，一个字符构成的串没有前后缀，长度为0
		int p = 0;     // p为前缀后一个字符坐标
		for(int i = 2;i < str.length();) {
			if(str.charAt(i - 1) == str.charAt(p)) { // 相等
				next[i] = ++p;                       // 坐标加一即表示匹配到的前缀长度
				i++;
			}else {                                  // 不相等
				if(p > 0) {      // 不相等，若前缀长度不为0，再找更小的前缀
					p = next[p];
				}else {          // 不相等，若前缀长度为0了，即p来到了模式串的开头
					next[i] = 0; // 没有匹配的前后缀，则next为0
					i++;         // i++
				}
			}
		}
		return new StringBuilder(s.substring(next[next.length - 1])).reverse() + s;
	}