### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.*;
class Solution {
    private HashMap<Character, Character> map;
    
    public Solution() {
        this.map = new HashMap<Character, Character>();
        this.map.put(')', '(');
        this.map.put('}', '{');
        this.map.put(']', '[');
    }


    public boolean isValid(String s) {
        if (s == null || s.length() % 2 != 0 ) {
            return false;
        }

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (!map.containsKey(c)) {
                stack.push(c);
                continue;
            }

            if (stack.isEmpty()) {
                return false;
            }

            if (map.get(c) != stack.pop()) {
                return false;
            }
        }

        
        return stack.isEmpty();
    }
}
```