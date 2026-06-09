### 解题思路
逆波兰表达式
---理解题意是关键

### 代码

```java
class Solution {
    public int evalRPN(String[] tokens) {
        //模拟栈的操作
        int[] numStack = new int[tokens.length / 2 + 1];
		int index = 0;
		for (String s : tokens) {
			switch (s) {
			case "+":
				numStack[index - 2] += numStack[--index];
				break;
			case "-":
				numStack[index - 2] -= numStack[--index];
				break;
			case "*":
				numStack[index - 2] *= numStack[--index];
				break;
			case "/":
				numStack[index - 2] /= numStack[--index];
				break;
			default:
				numStack[index++] = Integer.parseInt(s);
				break;
			}
		}
		return numStack[0];
    }
}
```