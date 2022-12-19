```
class Solution {
    public String reverseParentheses(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        Stack<Integer> sk = new Stack<>();
        for (int i=0; i<n; i++) {
            if (arr[i] == '(') {
                sk.push(i);
            } else if (arr[i] == ')') {
                int st = sk.pop();
                reverse(arr, st+1, i-1);
            }
        }
        StringBuilder ans = new StringBuilder();
        for (char c: arr)
            if (c != '(' && c != ')')
                ans.append(c);
        return ans.toString();
    }

    private void reverse(char[] arr, int st, int ed) {
        int i=st, j=ed;
        while (i < j) {
            char tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    }
}
```