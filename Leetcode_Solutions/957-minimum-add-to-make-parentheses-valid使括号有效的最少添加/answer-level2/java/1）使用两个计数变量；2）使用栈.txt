非栈方法：
![2020022701.PNG](https://pic.leetcode-cn.com/a402ad2e89c8d8b6674ae2cd8b1cc3a05136e3b6e4679093303f1d5240b46964-2020022701.PNG)
使用栈：
![2020022702.PNG](https://pic.leetcode-cn.com/d8770b504d229ce26c59cc6f8517dbfaf36ba224c398fea47b721bc8086853f6-2020022702.PNG)
### 解题思路
优先将"("和")"配对;

### 代码

```java
class Solution {
    public int minAddToMakeValid(String S) {
        //########使用两个计数变量
    	// int cnt = 0;
    	// int bal = 0;
    	// for(int i=0;i<S.length();i++) {
    	// 	if(S.charAt(i)=='(') {
    	// 		cnt++;
    	// 	}else if(S.charAt(i)==')') {
    	// 		cnt--;
    	// 		if(cnt==-1) {
    	// 			cnt++;
    	// 			bal++;
    	// 		}
    	// 	}
    	// }
    	// return cnt+bal;
        //##########使用栈
        Deque<Character> stack = new LinkedList<>();
    	for(int i=0;i<S.length();i++) {
    		if(stack.peek()==null||(stack.peek()=='('&&S.charAt(i)!=')')||(stack.peek()==')')) {
    			stack.push(S.charAt(i));
    		}else if(stack.peek()=='('&&S.charAt(i)==')') {
    			stack.poll();
    		}
    	}
    	return stack.size();
    }
}
```