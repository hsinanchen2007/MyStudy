```
public boolean isPalindrome(String s) {
        if("".equals(s) || s.length() == 1) {
			return true;
		}
		String str = s.toLowerCase();
		int len = str.length();
		int i = 0;
		int j = len - 1;
		while(i < j) {
			char l = str.charAt(i);
			char r = str.charAt(j);
			if(!((l >= 48 && l <= 57) || (l >= 97 && l <= 122))) {
				i++;
				continue;
			}
			if(!((r >= 48 && r <= 57) || (r >= 97 && r <= 122))) {
				j--;
				continue;
			}
			if(l != r) {
				return false;
			}
			i++;
			j--;
			if(i == j) {
				return true;
			}
		}
        return true;
    }
```
