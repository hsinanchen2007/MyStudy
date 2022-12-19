    
    class Solution {
        public int calculate(String s) {
            s = s.trim();
            char sign = '+';
            int d = 0;
            Stack<Integer> stack = new Stack<Integer>();
            for(int i = 0;i < s.length();i++) {
                if(s.charAt(i) == ' ') {
                    continue;
                }
                if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    d = d * 10 + (s.charAt(i) - '0');
                }
                if(i == s.length() - 1 || s.charAt(i) < '0') {
                    switch (sign) {
                    case '+':
                        stack.push(d);
                        break;
                    case '-':
                        stack.push(-d);
                        break;
                    case '*':
                        stack.push(stack.pop() * d);
                        break;
                    case '/':
                        stack.push(stack.pop() / d);
                        break;
                    default:
                        break;
                    }
                    sign = s.charAt(i);
                    d = 0;
                }
            }
            int res = 0;
            while(!stack.isEmpty()) {
                res += stack.pop();
            }
            return res;
        }
    }