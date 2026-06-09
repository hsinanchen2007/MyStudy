### 解题思路
从题解中了解到利用数组模拟栈空间并不需要将数组开到和String一样大，只需要开到s.length() / 2即可。
这里没用JDK中的java.util.Stack是由于刚开始利用JDK提供的Stack发现时间消耗太大。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if(s == null) return true;
        if(s.length() % 2 == 1) return false;
        char[] stack = new char[s.length() / 2];
        int size = 0;
        for(int i = 0; i < s.length(); i++){

            try {
                if (size == 0) {
                    stack[size++] = s.charAt(i);
                    continue;
                }
                if (s.charAt(i) == ')' && stack[size - 1] == '(') {
                    size--;
                } else if (s.charAt(i) == '}' && stack[size - 1] == '{') {
                    size--;
                } else if (s.charAt(i) == ']' && stack[size - 1] == '[') {
                    size--;
                } else {
                    stack[size++] = s.charAt(i);
                }
            }
            catch (ArrayIndexOutOfBoundsException e){
                return false;
            }
        }

        if(size == 0)
            return true;

        return false;

    }
}
```