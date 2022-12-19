``` java
    public String reverseParentheses(String s) {
        
        StringBuilder sb = new StringBuilder();
        char[] arr = s.toCharArray();
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < arr.length; i++) {
            
            if (arr[i] == '(')
                stack.push(i);
            
            if (arr[i] == ')')
                reverse(arr, stack.pop() + 1, i - 1);
        }
        
        for (int i = 0; i < arr.length; i++)
            if (arr[i] != ')' && arr[i] != '(')
                sb.append(arr[i]);
        
        return sb.toString();
    }
    
    public void reverse(char[] arr, int left, int right) {
        
        while (right > left) {
            
            char tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            right--;
            left++;
        }
    }
```