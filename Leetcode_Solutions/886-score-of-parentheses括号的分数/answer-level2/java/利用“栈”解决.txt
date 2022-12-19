### 解题思路
遍历字符串S中每个字符
1.若当前字符为（，直接入栈
2.若当前字符为）
   2.1若前一个字符为（，加“2的n-1次方”分（n为栈的深度）。然后弹出一个字符。
   2.2若前一个字符为），直接弹出一个字符。

### 代码

```java
class Solution {
    public int scoreOfParentheses(String S) {
		int score = 0;
		int length = S.length();
		Stack<Character> stack = new Stack<>();
		
		for(int i=0; i<length; i++){
			char temp = S.charAt(i);
			if(temp=='(')
				stack.add(temp);
			else{
				if(S.charAt(i-1)=='('){
					score += Math.pow(2, stack.size()-1);
					stack.pop();
				}else{
					stack.pop();
				}
			}
			
		}
		
		return score;
    }
}
```