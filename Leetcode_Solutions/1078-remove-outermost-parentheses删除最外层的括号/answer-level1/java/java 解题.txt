
char[] charS = s.toCharArray();
		String res = "";
		int count = 0;
		for(int i=0;i<s.length();i++) {
			if('(' == charS[i]) {
				if(count != 0) {
					res+=charS[i];
				}
				count++;
			}
			if(')' == charS[i]) {
				count--;
				if(count != 0) {
					res+=charS[i];
				}
			}
		}
		return res;