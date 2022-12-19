### 解题思路
看到很多Java题解用StringBuilder写的，就想发一个基础版的，虽然效率没有StringBuilder高。
StringBuilder+递归：用时：1ms；内存：34.3MB；
纯String + 递归：用时：10ms；内存：35.9MB。
第一次写题解，记录一下。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n == 1) return "1";
		else {
			int count = 1, j = 1;
			String s = countAndSay(n-1), res = "";
			for(; j<s.length(); j++) {
				if(s.charAt(j) == s.charAt(j-1)) {
					count ++;
				}
				else {
					res += count +""+ s.charAt(j-1);
					count = 1;
				}
			}
			return res + count +""+ s.charAt(j-1);
		}
    }
}
```
```
//StringBuilder递归
class Solution {
    public String countAndSay(int n) {
        if(n == 1) return "1";
		else {
            StringBuilder builder = new StringBuilder();
            String str = countAndSay(n-1);
            char pre = str.charAt(0);
            int count = 1;
            for (int j = 1; j < str.length(); j++) {
                char c = str.charAt(j);
                if (c == pre) {
                    count++;
                } else {
                    builder.append(count).append(pre);
                    pre = c;
                    count = 1;
                }
            }
            builder.append(count).append(pre);
            str = builder.toString();
            return str;
		}
    }
}
```
