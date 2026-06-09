### 解题思路
这种方法是不是特别笨，判断字符串的每一个字符以及它的后一个字符，不过速度还多快的

### 代码

```java
class Solution {
    public int romanToInt(String s) {
		int resu = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'I') {
				if (i < s.length() - 1) {
					if (s.charAt(i + 1) == 'V') {
						resu += 4;
						i++;
                        continue;
					} else if (s.charAt(i + 1) == 'X') {
						resu += 9;
						i++;
                        continue;
					}else
                        resu += 1;
				} else
					resu += 1;
			}
            if(s.charAt(i) == 'V'){
                resu += 5;
            }
			if (s.charAt(i) == 'X') {
				if (i < s.length() - 1) {
					if (s.charAt(i + 1) == 'L') {
						resu += 40;
						i++;
                        continue;
					} else if (s.charAt(i + 1) == 'C') {
						resu += 90;
						i++;
                        continue;
					} else {
						resu += 10;
					}
				} else
					resu += 10;
			}
			if (s.charAt(i) == 'L') {
				resu += 50;
			}
			if (s.charAt(i) == 'C') {
				if (i < s.length() - 1) {
					if (s.charAt(i + 1) == 'D') {
						resu += 400;
						i++;
                        continue;
					} else if (s.charAt(i + 1) == 'M') {
						resu += 900;
						i++;
                        continue;
					} else {
						resu += 100;
					}
				} else
					resu += 100;
			}
			if (s.charAt(i) == 'D')
				resu += 500;
			if (s.charAt(i) == 'M')
				resu += 1000;
		}
		return resu;
    }
}
```