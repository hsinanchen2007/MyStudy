本题的常规操作就是使用深度优先搜索，所以先说一下深度搜索的写法
- 大致的模样就是循环+递归
```
for(i = 0; i < len; i++){
    dfs(data, i);
}
``` 
- 在dfs函数中也是循环+递归，不过要有两个部分
    - 一个部分是结束条件
    - 另一个部分是继续搜索
```
dfs(data, level) {
    if(满足结束条件){
        return somedata;
    } else {
        for(..) {dfs(data, level + 1)}
    }
}
```
题目的解答如下：
```
class Solution {
    private List<String> result = new ArrayList<>();
  
    private char[][] chars = new char[10][];
  
    // 输入的数字
    private int[] numbers;
  
    public List<String> letterCombinations(String digits) {
        if (digits == null || "".equals(digits)) {
            return result;
        }

        chars[2] = new char[]{'a', 'b', 'c'};
        chars[3] = new char[]{'d', 'e', 'f'};
        chars[4] = new char[]{'g', 'h', 'i'};
        chars[5] = new char[]{'j', 'k', 'l'};
        chars[6] = new char[]{'m', 'n', 'o'};
        chars[7] = new char[]{'p', 'q', 'r', 's'};
        chars[8] = new char[]{'t', 'u', 'v'};
        chars[9] = new char[]{'w', 'x', 'y', 'z'};

        // 初始化输入
        char[] input = digits.toCharArray();
        numbers = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            numbers[i] = input[i] - 48;
        }

        // 开始深度搜索
        for (int i = 0; i < chars[numbers[0]].length; i++) {
            dfs(chars[numbers[0]][i] + "", 1);
        }
        return result;
    }

    private void dfs(String preStr, int level) {
        if (level == numbers.length) {
            result.add(preStr);
        } else {
            char[] chars = this.chars[numbers[level]];
            for (char ch : chars) {
                dfs(preStr + ch, level + 1);
            }
        }
    }
}
```
