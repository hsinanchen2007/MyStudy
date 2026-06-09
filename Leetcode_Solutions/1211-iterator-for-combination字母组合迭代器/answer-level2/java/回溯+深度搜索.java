### 解题思路
把字符串 按照给定长度排列问题，使用回溯+深度搜索算法完成。

### 代码

```java
class CombinationIterator {

    List<List<Character>> result = new ArrayList<>();
    public CombinationIterator(String characters, int combinationLength) {
        char[] chars = characters.toCharArray();
        Stack<Character> stack = new Stack<>();
        int len = chars.length;

        backtracedfs(result, 0, stack, chars, len, combinationLength);

    }

    private void backtracedfs(List<List<Character>> result, int index, Stack<Character> stack, char[] chars, int len,
            int limit) {

        if (stack.size() == limit) {
            result.add(new ArrayList<>(stack));
            return;
        }

        for (int i = index; i < len; i++) {
            stack.add(chars[i]);
            backtracedfs(result, i + 1, stack, chars, len, limit);
            stack.pop();
        }

    }

    public String next() {
        if (result.size() > 0) {
            List<Character> temp = result.remove(0);
            StringBuilder builder = new StringBuilder();
            for (Character c : temp) {
                builder.append(c);
            }
            return builder.toString();
        }

        return null;
    }

    public boolean hasNext() {
        return result.size() != 0;
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```