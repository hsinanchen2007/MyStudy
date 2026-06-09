### 解题思路
左边的就丢栈里边，右边的就取出栈顶判断是否相等，不相等或者有右值栈长度为0,返回false，直到栈的长度为0

### 代码

```java
class Solution {
    private HashMap<Character,Character> mappings;//查找肯定想到hashmap
    public Solution(){
        this.mappings = new HashMap<Character,Character>();
        this.mappings.put(')','(');
        this.mappings.put(']','[');
        this.mappings.put('}','{');
    }
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(this.mappings.containsKey(c)){
                char topElement = stack.empty() ? '#' : stack.pop();
                if(topElement != this.mappings.get(c)){
                    return false;
                }
            }else{
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}


```