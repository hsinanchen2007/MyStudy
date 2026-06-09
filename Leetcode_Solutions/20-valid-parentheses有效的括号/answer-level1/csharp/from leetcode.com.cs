### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool IsValid(string s) {
        Stack<char> stack= new Stack<char>();
        foreach (char c in s.ToCharArray()) {
            if (c == '(') {
                stack.Push(')');
            }else if (c == '{') {
                stack.Push('}');
            }else if (c == '['){
                stack.Push(']');
            }else if (stack.Count() == 0 || stack.Pop() != c){
                return false;
            }
        }
        return stack.Count() == 0;
    }
}
```