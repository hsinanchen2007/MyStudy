![l.png](https://pic.leetcode-cn.com/6719cd03358551f6d1ea19a599aac3e467f1bcb709feda96fb1b48f5e695c11a-l.png)


### 解题思路
用栈做辅助，将左括号入栈，遇到右括号时栈顶必须是对应的左括号才有效。

但是搞不通，测试用例中的空字符串竟然是有效括号。。。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if(s==null||s.length()<1){
            return "".equals(s);
        }
        int len=s.length();
        if((len&1)==1){
            return false;
        }
        Stack<Character> buffer=new Stack();
        for(int i=0;i<len;i++){
            char c=s.charAt(i);
            if(c=='{'||c=='['||c=='('){
                buffer.push(s.charAt(i));
            }else{
                if(buffer.isEmpty()||!isPair(buffer.pop(),c)){
                    return false;
                }
            }
        }
        return buffer.isEmpty();
    }
    
    private boolean isPair(char c1,char c2){
        switch(c1){
            case '(':
                return c2==')';
            case '[':
                return c2==']';
            case '{':
                return c2=='}';
        }
        return false;
    }
}
```