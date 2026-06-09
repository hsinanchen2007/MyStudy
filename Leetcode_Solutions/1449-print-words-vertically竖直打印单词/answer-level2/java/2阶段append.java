### 解题思路
2阶段append
1. 循环，如果没有字符了，那么append到临时的空字符串
2. 如果遇到字符了，那么补上之前临时的空字符串，再增加当前字符
### 代码

```java
class Solution {
    public List<String> printVertically(String s) {
        List<String> rst = new ArrayList<String>();
		String[] sp = s.split(" ");
		
		for(int i=0;;i++) {
			boolean ct = false;
			StringBuilder sb = new StringBuilder();
			StringBuilder tmp = new StringBuilder();
			for(int j=0;j<sp.length;j++) {
				if(sp[j].length()>i) {
					ct = true;
					sb.append(tmp).append(sp[j].charAt(i));
					tmp =  new StringBuilder();
				}else {
					tmp.append(" ");
				}
				
			}
			if(ct) {
				rst.add(sb.toString());
			}else {
				break;
			}
		}
		return rst;
    }
}
```