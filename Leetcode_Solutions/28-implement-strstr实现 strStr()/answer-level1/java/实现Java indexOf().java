代码在下面，多余的就不说了，希望各位大神给个建议。执行用时2 ms 内存消耗36.2 MB 

public static int strStr(String haystack, String needle) {
		if (needle.length() == 0) {
			return 0;
		} else {
			if (haystack.contains(needle)) {
				for (int i = 0; i < haystack.length(); i++) {
					String str = haystack.substring(i, haystack.length());
					if (str.contains(needle) && needle.equals(str.substring(0, needle.length()))) {
						return i;
					} else {
						continue;
					}
				}
			} else {
				return -1;
			}
		}
		return 0;
	}