##### DFS递归遍历过程

```
示例: "a1b2"
                  起始
第一次        a           A
第二次        1           1
第三次     b     B      b    B
第四次     2     2      2    2

PS：第四次遍历到达递归终止条件
```
##### 根据上述示例写出代码
```
    public List<String> letterCasePermutation(String S) {
        List<String> result = new ArrayList<>();
        dfs(S, 0, new char[S.length()], result);
        return result;
    }

    public void dfs(String S, int start, char[] chars, List<String> result) {
        // 1. 递归终止条件
        if(start == S.length()) {
            result.add(String.valueOf(chars));
            return;
        }

        // 2. 当前层逻辑处理
        char c = S.charAt(start);
        chars[start] = c;

        // 3. 递归下探
        dfs(S, start + 1, chars, result);

        // 2. 当前层逻辑处理
        if(Character.isLetter(c)) {
            chars[start] = Character.isUpperCase(c) ? Character.toLowerCase(c): Character.toUpperCase(c);
            // 3. 递归下探
            dfs(S, start + 1, chars, result);
        }
    }
```
