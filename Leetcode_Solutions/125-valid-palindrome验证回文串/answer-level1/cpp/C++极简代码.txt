bool isPalindrome(string s) {
		int j = s.length() - 1;
		int i = 0;
		while (i < j) {
			while (i<j && !(isdigit(s[i]) || isalpha(s[i]))) {
				i++;
			}
			while (i<j && !(isdigit(s[j]) || isalpha(s[j]))) {
				j--;
			}
			if (toupper(s[i]) != toupper(s[j])) {
				return false;
			}
			i++;
			j--;
		}
		
		return true;
	}