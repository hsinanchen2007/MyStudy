只需要将有效的得分添加进栈中，最后计算和即可
```
import java.util.*
class Solution {
    fun calPoints(ops: Array<String>): Int {
        val stack = Stack<Int>()
        for (op in ops) {
            if (op.toIntOrNull() == null) {
                if (!stack.isEmpty()) {
                    when (op) {
                        "C" -> {
                            stack.pop()
                        }
                        "D" -> {
                            stack.push(stack.peek() * 2)
                        }
                        "+" -> {
                            if (stack.size >= 2) {
                                stack.push(stack.peek() + stack[stack.size - 2])
                            }
                        }
                    }
                }

            } else {
                stack.push(op.toInt())
            }
        }
        var result = 0
        stack.forEach { 
            result+=it
        }
        return result
    }
}
```


