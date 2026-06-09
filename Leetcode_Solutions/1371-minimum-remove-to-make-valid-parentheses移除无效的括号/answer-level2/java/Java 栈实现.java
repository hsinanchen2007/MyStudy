思路：利用栈存储左括号，当遇到右括号时，进行判断，如果此时栈为空，那么此时')'的位置应该删除，我们先修改为' '，如果栈不为空，那么弹出栈顶元素，当遇到左括号时，把左括号的索引添加到栈里。最后while循环外面，栈里所有的左括号都是多余的，需要进行删除，最后利用replaceAll()方法进行替换即可。
```
class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> stack = new Stack<>();
        char[] ch = s.toCharArray();
        for(int i = 0;i < ch.length;i++){
            if(ch[i] == ')'){
                if(stack.empty())
                    ch[i] = ' ';
                else
                    stack.pop();
            }
            else if(ch[i] == '(')
                stack.push(i);
        }
        while(!stack.empty())
            ch[stack.pop()] = ' ';
        String ans = new String(ch);
        ans = ans.replaceAll(" ","");
        
        return ans;
    }
}
```
