class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            switch (c) {
                case '[':
                case '(':
                case '{':
                    stack.push(c);
                    break;
                default:
                    if(stack.empty())
                        return false;
                    char tmp = stack.pop();
                    if ((tmp=='('&&c!=')')||(tmp=='{'&&c!='}')||(tmp=='['&&c!=']'))
                        return false;
            }
        }
        return stack.empty();
    }
}