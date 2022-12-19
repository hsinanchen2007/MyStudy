### 解题思路
超过了91%的Java用户，难道我这个还不错？
思路应该说不难，只要不用自己手写一个栈就好，不知道面试的时候机试的ide有没有这么智能
大致如下：依次判断每个字符，如果是左边三个之一，直接进栈，否则判断栈是否为空，若为空直接false，否则就判断当前字符是否和栈顶字符匹配，若匹配则出栈顶元素，开始判断下一个元素，否则false

判断完后如果栈为空则true

我奇怪的点在于，我注释掉的那些为什么就通不过呢，问题出在栈内元素是char？

于2020年3月14日

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        // Stack<Character> stack = new Stack<Character>();
        // char[] chars=s.toCharArray();

        // for(int i=0;i<chars.length;i++){
        //     if(chars[i]=='('||chars[i]=='['||chars[i]=='{'){
        //         stack.push(chars[i]);
        //     }else{
        //         if(stack.isEmpty()){
        //             return false;
        //         }else{
        //             if(isRight(chars[i],stack.peek())){
        //                 stack.pop();
        //             }else{
        //                 return false;
        //             }
        //         }
        //     }
        // }

        Stack<String> stack=new Stack<String>();

        for(int i=0;i<s.length();i++){
			if(s.charAt(i)=='('||s.charAt(i)=='['||s.charAt(i)=='{'){
				stack.push(String.valueOf(s.charAt(i)));
			}else{
				if(stack.isEmpty()){
					return false;
				}else{
					if(isRight(stack.peek().toCharArray()[0], s.charAt(i))){
						stack.pop();
					}else{
						return false;
					}
				}
			}
		}


        if(stack.isEmpty()) return true;
        return false;
    }
    public static boolean isRight(char c1,char c2){
        if(c1=='('&&c2==')') return true;
        if(c1=='['&&c2==']') return true;
        if(c1=='{'&&c2=='}') return true;
        return false;
    }
}
```