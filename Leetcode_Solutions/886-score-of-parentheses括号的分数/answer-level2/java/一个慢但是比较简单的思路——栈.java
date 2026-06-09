这里采用了这样一种思路
栈中存储“（"，一旦遇到")"，就开始弹出栈中的数据，直到遇到“（"为止。

而我们知道的是，() = 1,  (()) = 1 * 2，()() = 1 + 1, 因此我们需要将计算结果保存下来，以备下次计算。
于是我用了这样的一种思路，每次计算完一个()后，都将计算结果压入栈中，直到遇到")"，我们就开始弹栈，直到遇到“（"为止，在"()"里面的数据求和，去掉"()"时 * 2


```
    public int scoreOfParentheses(String S) {

        Stack<String> stack = new Stack<>();

        for(char c : S.toCharArray()){
            if(c == '(')stack.push(String.valueOf(c));
            else{
                //System.out.println(stack);
                int ans = 0;
                if(stack.peek().equals("(")) ans = 1; 
                else{
                    while(!stack.isEmpty() && !stack.peek().equals("(")){
                        ans += Integer.parseInt(stack.pop());
                    }
                    ans *= 2;
                } 

                stack.pop();

                stack.push(String.valueOf(ans));
            }
        }
        
        int sum = 0;

        while(!stack.isEmpty()){
            sum += Integer.parseInt(stack.pop());
        }

        return sum;
    }
```
