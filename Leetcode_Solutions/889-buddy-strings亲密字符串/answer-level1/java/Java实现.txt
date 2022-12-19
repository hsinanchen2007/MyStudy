```
class Solution {
    public static boolean buddyStrings(String A, String B) {
		boolean flag = true;
		int num1 = -1, num2 = -1;
		char[] ch1 = A.toCharArray();
		char[] ch2 = B.toCharArray();
		if (ch1.length != ch2.length)
			return false;
		else {
			for (int i = 0; i < ch2.length; i++) {
				if (ch1[i] != ch2[i]) {
					if (flag) {
						num1 = i;
						flag = false;
					} else
						num2 = i;
				}
			}
		}
		if (num1 == -1) {
			for (int i = 0; i < ch1.length; i++) {
				for (int j = i + 1; j < ch1.length; j++) {
					if (ch1[i] == ch1[j]) {
						return true;
					}
				}
			}
			return false;
		} else {
			if (num2 == -1)
				return false;
			else {
				if (ch1[num1] == ch2[num2] && ch1[num2] == ch2[num1])
					return true;
				else
					return false;
			}
		}
	}
}
```

```
