```
class Solution {
    
    public int evalRPN(String[] tokens) {
        if(tokens == null) return 0;
        List<String> signs = new ArrayList<>();
        signs.add("+");
        signs.add("-");
        signs.add("*");
        signs.add("/");
        Stack<Integer> s = new Stack<>();
        int res = 0;
        for(int i = 0; i < tokens.length; i++){
            if(signs.contains(tokens[i])){
                int y = s.pop();
                int x = s.pop();
                res = cal(x, y, tokens[i]);
                s.push(res);
            }else
                s.push(Integer.parseInt(tokens[i]));
        }
        
        return s.peek();
    }
    
    public int cal(int x, int y, String sign){
        if(sign.equals("+"))
            return x + y;
        if(sign.equals("-"))
            return x - y;
        if(sign.equals("*"))
            return x * y;
        if(sign.equals("/"))
            return x / y;
        return -1;
    }
}
```
