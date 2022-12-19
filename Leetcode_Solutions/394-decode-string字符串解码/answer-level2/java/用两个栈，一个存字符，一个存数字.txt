### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String decodeString(String s) {
        Stack<Character> s1 = new Stack<Character>();
		Stack<Integer> s2 = new Stack<Integer>();
		String tempNumber="";
		for(int i=0;i<s.length();i++) {
			if(Character.isDigit(s.charAt(i))) {
				tempNumber+=s.charAt(i);
				continue;
			}
			else if(s.charAt(i)==']') {
				String temp="";
				while(!s1.isEmpty()) {
					Character pop = s1.pop();
					if(pop=='[') {
						break;
					}
					else {
						temp=pop+temp;
					}
				}
				String temp2="";
				Integer num = s2.pop();
				for(int j=0;j<num;j++) {
					temp2+=temp;
				}
				for(int j=0;j<temp2.length();j++) {
					s1.push(temp2.charAt(j));
				}
			}
			else if(s.charAt(i)=='['){
				Integer m = Integer.valueOf(tempNumber);
				s2.push(m);
				tempNumber="";
				s1.push(s.charAt(i));
			}else {
				s1.push(s.charAt(i));
			}
		}
		String str="";
		while(!s1.isEmpty()) {
			str=s1.pop()+str;
		}
		return str;
    }
}
```