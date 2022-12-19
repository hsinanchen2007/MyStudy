### 解题思路
使用简易方法和栈 有一倍左右的性能差距

### 代码

```kotlin
import java.util.*
class Solution {
    fun isValid(s: String): Boolean {
        val map = hashMapOf(')' to '(', '}' to '{', ']' to '[')
        val stack :Stack<Char> = Stack()
        s.forEach {
            if(map.containsKey(it)){
                if(stack.isEmpty()) return false
                if(stack.pop() != map[it]) return false
            }else{
                stack.push(it)
            }
        }
        return stack.isEmpty()
    }
}
```

```kotlin
class Solution {
    fun isValid(s: String): Boolean {
        var info = s
        //不停的删除(){}[]
        while(info.contains("()") || info.contains("{}") || info.contains("[]")){
            info = info.replace("()","").replace("{}","").replace("[]","")
        }
        return info.isEmpty()
    }
}
```