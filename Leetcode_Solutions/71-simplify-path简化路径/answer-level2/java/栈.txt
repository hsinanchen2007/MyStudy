### 解题思路
如果识别到正常的目录则将其入栈，如果监测到..则将栈顶元素弹出，回到上一级目录。

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<String>();
        int i = 0;
        int j = 0;
        while(i < path.length()) {
        	if(path.charAt(i) == '/') {
        		i++;
        		continue;
        	}
        	StringBuilder sb = new StringBuilder();
        	j = i;
        	while(j < path.length() && path.charAt(j) != '/') {
        		sb.append(path.charAt(j));
        		j++;
        	}
        	i = j;
        	if(sb.toString().equals(".")) {
        		// Do nothing
        	}
        	else if(sb.toString().equals("..")) {
        		if(!stack.isEmpty()) {
        			stack.pop();
        		}
        	}
        	else {		// Normal
        		sb.insert(0, '/');
        		stack.push(sb.toString());
        	}
        }
        StringBuilder sb = new StringBuilder();
        if(stack.isEmpty()) {
        	sb.append('/');
        }
        while(!stack.isEmpty()) {
        	sb.insert(0, stack.pop());
        }
        return sb.toString();
    }
}
```