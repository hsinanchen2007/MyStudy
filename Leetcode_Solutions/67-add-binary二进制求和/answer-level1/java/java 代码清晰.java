```
public String addBinary(String a, String b) {
		int carry = 0;
		int i = a.length() - 1;
		int j = b.length() - 1;
		StringBuilder sb = new StringBuilder();
		while (i >= 0 || j >= 0) {
			int x = i >= 0 && a.charAt(i) == '1' ? 1 : 0;
			int y = j >= 0 && b.charAt(j) == '1' ? 1 : 0;
			int sum = x + y + carry;
			carry = sum / 2;
			sb.append(sum % 2);
			i--;
			j--;
		}
		if (carry == 1) {
			sb.append(1);
		}
		return sb.reverse().toString();
	}
```
