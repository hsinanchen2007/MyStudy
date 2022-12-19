### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        return simpleStr(S).equals(simpleStr(T));
    }

    private Stack<Character> simpleStr(String S) {
        Stack<Character> s1 = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            s1.push(S.charAt(i));
            if (S.charAt(i) == '#') {
                if (!s1.empty()) s1.pop();
                if (!s1.empty()) s1.pop();
            }
        }
        return s1;
    }
}
```