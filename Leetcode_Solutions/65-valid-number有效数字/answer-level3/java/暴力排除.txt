执行结果：
通过
显示详情
执行用时 :
5 ms
, 在所有 Java 提交中击败了
96.95%
的用户
内存消耗 :
35.9 MB
, 在所有 Java 提交中击败了
89.92%
的用户

```
class Solution {
    public boolean isNumber(String s) {
	    s = s.trim();
		int len = s.length();
		if (len == 0)
			return false;

		if (len == 1 && !(s.charAt(0) >= '0' && s.charAt(0) <= '9'))
			return false;
		int sign = 0;
		int dot = 0;
		int counte = 0;
		boolean preHasNumber = false;
		boolean firstaftere = false;
		boolean aftere = false;
		char last = s.charAt(0);
		for (int i = 0; i < len; i++) {
			char c = s.charAt(i);
			if (c == ' ') {
				if (last == '.' || last >= '0' && last <= '9') {
					return false;
				}
				if (sign > 0)
					return false;
				continue;
			}

			if (!(c >= '0' && c <= '9' || c == '-' || c == '+' || c == 'e' || c == '.'))
				return false;
			if (i == 0) {
				if (c >= '0' && c <= '9') {
					preHasNumber = true;
				} else if (c == '+' || c == '-') {
					sign++;
				} else if (c == 'e') {// e
					return false;
				} else if (c == '.') {
					dot++;
				}
				last = c;
				continue;
			}
			if (c == '-' || c == '+') {
				if (preHasNumber || dot > 0)
					return false;
				sign++;
			}
			if (sign > 1)
				return false;
			if (c == '.') {
				// if(!preHasNumber)return false;
				dot++;
			}
			if (dot > 1)
				return false;

			if (c == 'e') {
				counte++;
				if (counte > 1)
					return false;
				if (!(last >= '0' && last <= '9' || (last == '.' && preHasNumber))) {
					return false;
				}

				firstaftere = true;
				sign = 0;
				dot = 0;
				preHasNumber = false;
				aftere = true;

				last = c;
				continue;
			}
			if (aftere) {
				if (c == '.')
					return false;
				if (firstaftere) {
					firstaftere = false;
					if (c >= '0' && c <= '9') {
						preHasNumber = true;
					}
					last = c;
					continue;
				}
			}
			if (c >= '0' && c <= '9')
				preHasNumber = true;
			last = c;
		}
		if (!(last >= '0' && last <= '9' || last == '.')) {
			return false;
		}
		if (last == '.' && !preHasNumber)
			return false;
		return true;
    }
}
```
