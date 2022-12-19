### 解题思路

比较经典的题，没什么好说的，经测试，双指针完胜栈

### 代码

双指针代码：

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        if(S==null || S.length()==0) return "";
		char ss[] = S.toCharArray();
		int i = 0;
		int j = ss.length-1;
		while(i<j) {
			while(i<j && !Character.isLetter(ss[i])) {
				i++;
			}
			while(i<j && !Character.isLetter(ss[j])) {
				j--;
			}
			char temp = ss[i];
			ss[i] = ss[j];
			ss[j] = temp;
			i++;
			j--;
		}
		return new String(ss);
    }
}
```

栈 代码：
```java
public static String reverseOnlyLetters(String S) {
	Stack<Character> stack = new Stack<>();
	String reslut = "";
	
	for(int i=0;i<S.length();i++) {
		if(Character.isLetter(S.charAt(i))) {
			stack.push(S.charAt(i));
		}
	}
	for(int i=0;i<S.length();i++) {
		if(Character.isLetter(S.charAt(i))) {
			reslut+=stack.pop();
		}else {
			reslut+=S.charAt(i);
		}
	}
	return reslut;
}
```