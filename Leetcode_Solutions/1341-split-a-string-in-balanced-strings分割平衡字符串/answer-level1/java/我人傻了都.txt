### 解题思路
执行用时 :
3 ms
, 在所有 java 提交中击败了
12.03%
的用户
内存消耗 :
35.6 MB
, 在所有 java 提交中击败了
100.00%
的用户

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
         int res_spilt=0;
        Stack stack=new Stack<String>();
        char[] s_char=s.toCharArray();
        for(int i=0;i<s_char.length;i++) {
        	
        	
        		if(stack.isEmpty()) {
        			stack.push(String.valueOf(s_char[i]));
        		}else {
        			if(String.valueOf(s_char[i]).equals(stack.peek())) {
        				stack.push(String.valueOf(s_char[i]));
        			}else {
        				stack.pop();
        				if(stack.isEmpty()) {
        					res_spilt++;
        				}
        			}
        		}
        		
        	
        	
        }
        return res_spilt;
        
    }
}
```