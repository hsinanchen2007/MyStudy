执行用时 :6 ms, 在所有 Java 提交中击败了94.51%的用户
内存消耗 :37.3 MB, 在所有 Java 提交中击败了96.11%的用户

**大部分需要栈结构实现的算法都可以用数组模拟**，而且或更快，内存消耗更小。

解题思路：
- 使用两个模拟栈: `chStack`记录最后出现的字符，如果连续出现，只入栈一个即可。`numStack`记录对应`chStack`栈字符出现的次数
- `index`模拟栈的大小
- 当栈为空或者栈顶元素跟当前字符不相同时，字符压入chStack栈,numStack初始置1；当栈顶元素和当前字符相同时,若numStack栈顶元素值+1==k（`numStack[index-1]==k`）可消除k个字符，只需模拟栈大小减1即可:`index--`，否则numStack栈顶元素值+1(`numStack[index-1]++`)
<br>
#### 附上纯数组实现和栈实现的对比代码
```java
class Solution {
        //纯数组实现   消耗：6 ms	37.3 MB
	public static String removeDuplicates(String s, int k) {
		char[] ss = s.toCharArray();
		int index = 0;//模拟栈大小
		char[] chStack = new char[ss.length];//字符栈
		int[] numStack = new int[ss.length];//计数栈
		for (char ch : ss) {
			// 栈为空或者ch和栈顶元素不相同，入栈，并初始化连续出现数量为1
			if (index == 0 || chStack[index - 1] != ch) {
				chStack[index] = ch;
				numStack[index++] = 1;
			} else if (chStack[index - 1] == ch) {
				// 字符栈顶元素已连续出现k-1次，且加上当前字符后满足连续k个，2个栈顶都出栈
				if (numStack[index - 1] + 1 == k) {
					index--;
				} else {
					// 与字符栈顶元素相同但未满足k，计数栈栈顶加1
					numStack[index - 1]++;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < index; i++) {
			for (int j = 0; j < numStack[i]; j++) {
				sb.append(chStack[i]);
			}
		}
		return sb.toString();
	}


    //栈实现   消耗：53 ms	38.4 MB
    public String removeDuplicates_stack(String s, int k) {
		Stack<Character> chStack = new Stack<>();
		Stack<Integer> numStack = new Stack<>();
		for (char ch : s.toCharArray()) {
			// 栈为空或者ch和栈顶元素不相同，入栈，并初始化连续出现数量为1
			if (chStack.isEmpty() || chStack.peek() != ch) {
				chStack.push(ch);
				numStack.push(1);
			} else if (chStack.peek() == ch) {
				// 字符栈顶元素已连续出现k-1次，且加上当前字符后满足连续k个，2个栈顶都出栈
				if (numStack.peek() + 1 == k) {
					numStack.pop();
					chStack.pop();
				} else {
					// 与字符栈顶元素相同但未满足k，计数栈栈顶加1
					numStack.push(numStack.pop() + 1);
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		while (!numStack.isEmpty()) {
			int repeat = numStack.pop();
			char repeatCh = chStack.pop();
			for (int i = 0; i < repeat; i++) {
				sb.insert(0, repeatCh);
			}
		}
		return sb.toString();
    }
}
```