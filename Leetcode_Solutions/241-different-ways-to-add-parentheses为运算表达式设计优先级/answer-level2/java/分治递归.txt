### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> ways = new ArrayList<>();
    for (int i = 0; i < input.length(); i++) {
        char c = input.charAt(i);
        // 如果遇到符号则要获取其左右两侧的结果集合——分解
        if (c == '+' || c == '-' || c == '*') {
            //找到当前i的左右两侧的所有的可能结果
            // diffWaysToCompute 递归函数求出子问题的解——左右全部的结果
            List<Integer> left = diffWaysToCompute(input.substring(0, i));
            List<Integer> right = diffWaysToCompute(input.substring(i + 1));
            //根据运算符合并子问题的解——合并
            for (int l : left) {
                for (int r : right) {
                    switch (c) {
                        case '+':
                            ways.add(l + r);
                            break;
                        case '-':
                            ways.add(l - r);
                            break;
                        case '*':
                            ways.add(l * r);
                            break;
                    }
                }
            }
        }
    }
    if (ways.size() == 0) {
        //强转为int
        ways.add(Integer.valueOf(input));
    }
    return ways;
    }
}
```