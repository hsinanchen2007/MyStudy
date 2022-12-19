
我看到之后的思路： 肯定是偶数位的，需要判断一下；然后根据题意吧你从外往里头所经历的结果会太多太多，但是从中间的里头往外头走就没事了，并且正中间一定会是一对括号的；然后有一个只用字符串自带方法的解题；
```java
public static boolean isValid(String s) {
	        if (s.contains("()") || s.contains("[]") || s.contains("{}")) {
	            return isValid(s.replace("()", "").replace("[]", "").replace("{}", ""));
	        } else {
	            return "".equals(s);
	        }
	    }
}
```

这种方式所占用的内存空间肯定是很大的吧；递归加字符串频繁操作；

然后官方给出的解题是还是需要从外往内但是他借助了栈，还有hashmap，然后它的代码是：
```java
class Solution {

  // Hash table that takes care of the mappings.
  private HashMap<Character, Character> mappings;

  // Initialize hash map with mappings. This simply makes the code easier to read.
  public Solution() {
    this.mappings = new HashMap<Character, Character>();
    this.mappings.put(')', '(');
    this.mappings.put('}', '{');
    this.mappings.put(']', '[');
  }

  public boolean isValid(String s) {

    // Initialize a stack to be used in the algorithm.
    Stack<Character> stack = new Stack<Character>();

    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);

      // If the current character is a closing bracket.
      if (this.mappings.containsKey(c)) {

        // Get the top element of the stack. If the stack is empty, set a dummy value of '#'
        char topElement = stack.empty() ? '#' : stack.pop();

        // If the mapping for this bracket doesn't match the stack's top element, return false.
        if (topElement != this.mappings.get(c)) {
          return false;
        }
      } else {
        // If it was an opening bracket, push to the stack.
        stack.push(c);
      }
    }

    // If the stack still contains elements, then it is an invalid expression.
    return stack.isEmpty();
  }
}
```

然后其实按照他的写法还有能优化的地方，比如说是null或者length是奇数的情况都可以直接判定；还有就是当拿到第一个闭合括号的时候栈顶元素不匹配那也可以直接false了等吧；所以说是还可以加点小优化的；
