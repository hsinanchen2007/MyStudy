    
    class Solution {
        public int calculate(String s) {
            int[] index = new int[1];
            return dfs(s, index);
        }

        public int dfs(String s, int[] index) {
            int d = 0;
            char sign = '+';
            Stack<Integer> stack = new Stack<>();
            for(int i = index[0];i < s.length();i++) {
                if(s.charAt(i) == '(') {
                    index[0] = i + 1;
                    d = dfs(s, index);
                    i = index[0];
                    if(i == s.length()) {
                        stack.push(sign == '+' ? d : -d);
                        break;
                    }
                }else if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    d = d * 10 + (s.charAt(i) - '0');
                }
                if(i == s.length() - 1 || s.charAt(i) == '+' || s.charAt(i) == '-' || s.charAt(i) == ')') {
                    stack.push(sign == '+' ? d : -d);
                    sign = s.charAt(i);
                    d = 0;
                    if(s.charAt(i) == ')') {
                        index[0] = i + 1;
                        break;
                    }
                }
            }
            int sum = 0;
            while(!stack.isEmpty()) {
                sum += stack.pop();
            }
            return sum;
        }
    }