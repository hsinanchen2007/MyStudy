**1、第一种，也就是最容易想到的，调用栈**
这里我用到了异常，总体来说效率堪忧
```
    public int evalRPN(String[] tokens) {
        int ans = 0;
        if (tokens.length == 0) return ans;
        Stack<Integer> stack = new Stack<>();
        stack.add(Integer.valueOf(tokens[0]));

        for (int i = 1; i < tokens.length; i++) {
            try {
                int num = Integer.valueOf(tokens[i]);
                stack.add(num);
            } catch (Exception e) {
                Integer num1 = stack.pop();
                Integer num2 = stack.pop();
                switch (tokens[i]) {
                    case "+":
                        ans = num1 + num2;
                        break;
                    case "-":
                        ans = num2 - num1;
                        break;
                    case "*":
                        ans = (num1 * num2);
                        break;
                    case "/":
                        ans = (num2 / num1);
                        break;
                }
                stack.add(ans);
            }
        }
        return stack.pop();
    }
```
**第二种使用数组存储数字，遇到运算符就运算**
运行以后，发现效率还不错
```
public int evalRPN2(String[] tokens) {
        int[] nums = new int[tokens.length];
        int ansInd = -1;
        for (int i = 0; i < tokens.length; i++) {
            if ("+".equals(tokens[i]) || "-".equals(tokens[i])
                    || "*".equals(tokens[i]) || "/".equals(tokens[i])) {
                int num1 = nums[ansInd - 1];
                int num2 = nums[ansInd];
                switch (tokens[i]) {
                    case "+":
                        nums[ansInd - 1] = num1 + num2;
                        break;
                    case "-":
                        nums[ansInd - 1] = num1 - num2;
                        break;
                    case "*":
                        nums[ansInd - 1] = (num1 * num2);
                        break;
                    case "/":
                        nums[ansInd - 1] = (num1 / num2);
                        break;
                }
                ansInd--;
            } else {
                nums[++ansInd] = Integer.valueOf(tokens[i]);
            }
        }
        return nums[ansInd];
    }
```

