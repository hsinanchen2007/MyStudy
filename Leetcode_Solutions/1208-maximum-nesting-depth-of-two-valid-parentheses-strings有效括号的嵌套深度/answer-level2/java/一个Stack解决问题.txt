```
public int[] maxDepthAfterSplit(String seq) {
        Stack<Integer> stack = new Stack();
        int len = seq.length();
        int[] res = new int[seq.length()];
        
        int t = 0;
        for(int i = 0; i < len; i++) {
            char c = seq.charAt(i);
            if (c == '(') {
                stack.push(i);
                res[i] = t;
                t = (t + 1) % 2;
            } else if (c == ')') {
                int index = stack.pop();
                res[i] = res[index];
                t = (t + 1) % 2;
            }
        }
        
        return res;
    }
```
