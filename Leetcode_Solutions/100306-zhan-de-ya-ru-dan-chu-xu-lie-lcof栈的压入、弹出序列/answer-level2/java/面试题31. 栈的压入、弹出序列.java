### 解题思路
巧妙运用入栈操作。
1.如果发现当前添加的数是popped指定的数，则pop(),popped后移，
  再用后移的popped数与当前栈顶的数比较，如果还相等则重复pop(),popped后移操作，反之则继续添加数到栈。
2.如果正确，则index能移动至popped的末尾。

### 代码

```java
class Solution {
    	public static boolean validateStackSequences(int[] pushed, int[] popped) {
		Stack<Integer>stack=new Stack<>();
		int index=0;//遍历popped
		for (int temp:pushed) {
			stack.add(temp);
			while(stack.size()!=0&&index<popped.length&&stack.peek()==popped[index]) {
				stack.pop();
				index++;
			}
		}
		return index==popped.length;
    }
}
```