
方法一：递归
```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        char[] chars = new char[n * 2];

        dfs(list, chars, 0, 0);

        return list;
    }

    private void dfs(List<String> list, char[] chars, int size, int stack) {
        if (stack > 0) {
            chars[size++] = ')';
            stack--;
            if (size == chars.length) {
                list.add(new String(chars));
            } else {
                dfs(list, chars, size, stack);
            }
            size--;
            stack++;
        }

        if (size + stack < chars.length) {
            chars[size++] = '(';
            stack++;
            if (size == chars.length) {
                list.add(new String(chars));
            } else {
                dfs(list, chars, size, stack);
            }
        }
    }
}
```


方法二：栈

```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();

        char[] stack = new char[n * 2];
        stack[0] = '(';
        int size = 1;
        int leftSize = 1;

        while (leftSize > 0) {
            
            while (leftSize < n) {
                stack[size++] = '(';
                leftSize++;
            }
            int lastSize = size;
            while (size < 2 * n) {
                stack[size++] = ')';
            }
            list.add(new String(stack));

            size = lastSize;
            while (leftSize > 1) {
                if (stack[size - 1] == ')') {
                    size--;
                } else if (leftSize == size - leftSize + 1) {
                    size--;
                    leftSize--;
                } else {
                    break;
                }
            }
            stack[size - 1] = ')';
            leftSize--;
        }
        return list;
    }
}
```

两种方法都可以在1ms完成