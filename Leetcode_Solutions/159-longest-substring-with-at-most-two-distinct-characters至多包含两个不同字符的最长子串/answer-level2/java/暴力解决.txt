### 解题思路
不停向stack中压入数据，当压入的数据时第三的时候，记录最大长度，再把stack中顶部的数据弹出，在计算下一次。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }
        char[] chars = s.toCharArray();
        Stack<Character> stack1 = new Stack<Character>();
        Stack<Character> stack2 = new Stack<Character>();
        int maxLength = 0;
        boolean isHaveSecChar = false;
        for (char tmp : chars) {
            if (stack1.isEmpty()) {
                stack1.add(tmp);
            } else if (stack1.contains(tmp)) {
                stack1.add(tmp);
            } else if (!isHaveSecChar) {
                stack1.add(tmp);
                isHaveSecChar = true;
            } else {
                maxLength = Math.max(maxLength, stack1.size());
                char topChar = stack1.pop();
                stack2.add(topChar);
                while (!stack1.isEmpty() && stack1.pop() == topChar) {
                    stack2.add(topChar);
                }
                stack1.clear();
                stack1.addAll(stack2);
                stack2.clear();
                stack1.add(tmp);
            }
        }
        maxLength = Math.max(maxLength, stack1.size());
        return maxLength;
    }
}
```