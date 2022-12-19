* 对给定字符串S进行顺序遍历，定义栈s
* 当前字符不为'c'时，字符入栈
* 当前字符为'c'时，先后进行两次s.pop()，并判断是否pop出b和a，若不是，则return false，在进行出栈操作时若栈空，则return false

```
class Solution {
    public boolean isValid(String S) {
        Stack<Character> s = new Stack<>();
        for(int i = 0; i < S.length(); i++){
            if(S.charAt(i) != 'c') s.push(S.charAt(i));
            else if(!s.isEmpty()){
                //若中途栈为空也是不成立的
                if(s.isEmpty() || s.pop() != 'b') return false;
                if(s.isEmpty() || s.pop() != 'a') return false;
            }
            else return false;
        }
        return s.isEmpty();
    }
}
```