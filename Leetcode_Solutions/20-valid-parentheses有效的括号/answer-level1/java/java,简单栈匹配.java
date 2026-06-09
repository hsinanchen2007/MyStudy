### 解题思路


### 代码

```java
class Solution {
    public boolean isValid(String s) {
        Deque stack = new ArrayDeque();
        for (char c : s.toCharArray()) {
            Character peek = (Character) stack.peek();
            if ((peek!=null)&&((peek=='['&&c==']')||(peek=='('&&c==')')||(peek=='{'&&c=='}'))){
                stack.poll();
                continue;
            }
            stack.push(c);
        }
        return stack.isEmpty();
    }
}
```