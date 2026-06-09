```java
    private char[] sStr;
	private char[] pStr;
	private int sSize;
	private int pSize;
	private boolean[][] vis;

	public boolean match(int is, int ip) {
		if (is == sSize) { //左串到底判断右串是否存在用*到底的可能
			if(ip == pSize) return true;
			if(ip + 1 != pSize && pStr[ip+1] == '*') return match(is, ip+2);
			return false;
		}
		if (ip == pSize) return false; // 右串到底左串任有为false
		if (vis[is][ip]) return false; // 基础动态规划
		vis[is][ip] = true;
		if (pStr[ip] == '.' || sStr[is] == pStr[ip]) { // s[is]和p[ip]成功匹配
			if (ip + 1 != pSize && pStr[ip+1] == '*') { // p[ip+1]是'*'，任然代表p[ip]或者不再代表p[ip]
				if (match(is + 1, ip) || match(is + 1, ip + 2)) return true;
			} else  return match(is + 1, ip + 1);
		}
		if(ip+1 != pSize && pStr[ip+1] == '*') return match(is, ip+2); // 无法匹配看是否存在右串用*吃掉p[ip]的情况
		return false;
	}

	public boolean isMatch(String s, String p) {
		sStr = s.toCharArray();
		pStr = p.toCharArray();
		sSize = s.length();
		pSize = p.length();
		vis = new boolean[sSize + 2][pSize+2];
		return match(0, 0);
	}
```
