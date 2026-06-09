```
class Solution {
    public int largestUniqueNumber(int[] A) {
        Arrays.sort(A);
        Stack<Integer> stack = new Stack<>();
        int tmp = -1;
        for (int i = A.length - 1; i >= 0; i--) {
            if (tmp == A[i]){
                continue;
            } else if (stack.empty()) {
                Integer a = A[i];
                stack.push(a);
            } else {
                int b = stack.peek();
                if (b == A[i]) {
                    tmp = stack.pop();
                }
            }
        }
        if (stack.empty()) {
            return -1;
        } else {
            int c = stack.peek();
            return c;
        }
    }
}
```
