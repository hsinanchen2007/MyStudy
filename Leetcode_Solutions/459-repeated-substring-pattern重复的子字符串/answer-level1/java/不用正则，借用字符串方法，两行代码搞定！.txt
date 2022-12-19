1.将原字符串给出拷贝一遍组成新字符串；
2.掐头去尾留中间；
3.如果还包含原字符串，则满足题意。
```
public boolean repeatedSubstringPattern(String s) {
		
	String str = s + s;
	return str.substring(1, str.length() - 1).contains(s);;
	}
```
