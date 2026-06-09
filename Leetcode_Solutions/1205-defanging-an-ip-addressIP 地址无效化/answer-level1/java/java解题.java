
public String defangIPaddr(String address) {
		char[] s = address.toCharArray();
		int i = s.length - 1;
		int j = s.length - 1;
		for (char c : s) {
			if (c == '.') {
				i += 2;
			}
		}
		char[] copys = new char[i + 1];
		while (i >= 0 && j >= 0) {
			if (s[j] != '.') {
				copys[i] = s[j];
				i--;
				j--;
			} else {
				copys[i] = ']';
				copys[i - 1] = '.';
				copys[i - 2] = '[';
				i -= 3;
				j -= 1;
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(copys);
		String ss = sb.toString();
		return ss;
	}