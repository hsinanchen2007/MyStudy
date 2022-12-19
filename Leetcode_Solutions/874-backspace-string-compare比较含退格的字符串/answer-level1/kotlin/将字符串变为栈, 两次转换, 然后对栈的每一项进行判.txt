### 解题思路
此处撰写解题思路

### 代码

```kotlin
import java.util.*

class Solution {
  fun backspaceCompare(S: String, T: String): Boolean {
    val sStack = parseString(S)
    val tStack = parseString(T)
    while (!sStack.isEmpty() && !tStack.isEmpty()) {
      if (sStack.pop() != tStack.pop()) {
        return false
      }
    }
    return tStack.isEmpty() && sStack.isEmpty() && true
  }

  fun parseString(str: String): Stack<Char> {
    val stack = Stack<Char>()
    val helpStack = Stack<Char>()
    for (char in str) {
      if (char == '#' && !stack.isEmpty()) {
        stack.pop()
      } else {
        if (char != '#') {
          stack.push(char)
        }
      }
    }
    while (!stack.isEmpty()) {
      helpStack.push(stack.pop())
    }
    return helpStack
  }
}
```