看到这道题的时候就觉得特别像计算器问题，就是给一个带有括号和运算符的字符串，计算最后的结果
直接把那类题的方法照搬过来即可，可以用数组来优化，用队列是为了更好的理解（对于我来说）

```
class Solution {
    public int scoreOfParentheses(String S) {
        Queue<Character> queue = new LinkedList();
        for (char c : S.toCharArray()) {
            queue.offer(c);
        }
        return compute(queue);
    }

    public int compute(Queue<Character> queue) {
        int num = 0;
        while (!queue.isEmpty()) {
            char c = queue.poll();
            if (c == '(') {
                int val = compute(queue);
                if (val == 0) {
                    num++;
                } else {
                    num += 2 * val;
                }
            } else {
                return num;
            }
        }
        return num;
    }
}

```
