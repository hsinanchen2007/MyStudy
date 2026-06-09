```java
class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> left, star;
        left = new Stack<>();
        star = new Stack<>();
        char[] arr = s.toCharArray();
        for (int i = 0; i < s.length(); i ++) {
            if (arr[i] == '(') left.push(i);
            else if (arr[i] == '*') star.push(i);
            else if (arr[i] == ')') {
                if (!left.isEmpty()) left.pop();
                else if (!star.isEmpty()) star.pop();
                else return false;
            }
        }
        while (!left.isEmpty() && !star.isEmpty()) {
            int ll = left.pop();
            int rr = star.pop();
            if (rr < ll) return false;
        }
        if (left.isEmpty()) return true;
        return false;
    }
}
```