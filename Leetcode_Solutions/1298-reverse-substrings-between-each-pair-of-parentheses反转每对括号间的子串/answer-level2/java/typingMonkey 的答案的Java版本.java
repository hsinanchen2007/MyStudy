**引用大神typingMonkey的思想，用Java复刻了一个答案，一次性通过。**
![1568879841(1).jpg](https://pic.leetcode-cn.com/89474a4acb152b1a68c3bab8dd1ddda892bb15b8e4cb94d36c71edd3f7a4d0e4-1568879841\(1\).jpg)


```
    public String reverseParentheses(String s) {
        Stack<String> stack = new Stack<>();
        stack.push("");
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c=='('){
                stack.push("");
            }else if(c==')'){
                String pop = stack.pop();
                StringBuilder pop2 = new StringBuilder(stack.pop());
                for (int k = pop.length()-1; k >= 0 ; k--) {
                    char cc = pop.charAt(k);
                    pop2.append(cc);
                }
                stack.push(pop2.toString());
            }else{
                String pop = stack.pop();
                pop+=c;
                stack.push(pop);
            }
        }
        return stack.pop();
    }
```
