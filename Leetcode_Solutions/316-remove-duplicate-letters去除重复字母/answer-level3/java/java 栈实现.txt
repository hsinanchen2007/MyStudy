# 解题思想:
1. 若栈中已经有当前元素，则直接去除当前元素
2. 若当前的栈顶元素比当前的元素字典序大，且当前元素的位置后面还有栈顶元素,
将栈顶元素出栈, 将当前元素入栈, 这样来找到最优的排列

```
class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            Character c = s.charAt(i);
            //1
            if(stack.contains(c)) continue;
            //2
            while(!stack.isEmpty() && stack.peek() > c && s.indexOf(stack.peek(), i) != -1)
                stack.pop();
            stack.push(c);
        }
        char[] res = new char[stack.size()];
        for(int i = 0; i < stack.size(); i++)
            res[i] = stack.get(i);
        
        return new String(res);
    }
}
```
