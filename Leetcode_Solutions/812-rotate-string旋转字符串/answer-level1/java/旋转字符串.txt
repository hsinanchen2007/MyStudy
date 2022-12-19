    // 暴力法
	public boolean rotateString(String A, String B) {
		if (A.equals(B)) {
			return true;
		}
		String rotateStr = A;
		for (int i = 0; i < rotateStr.length(); i++) {
			rotateStr = rotateStr.substring(1) + rotateStr.substring(0, 1);
			if (rotateStr.equals(B)) {
				return true;
			}
		}

		return false;
	}
	
	//根据A的旋转特性，B字符串一定是两个A串拼接字符串的子串
	public boolean rotateString_2(String A, String B) {
		return A.length() == B.length() && (A + A).contains(B);
	}