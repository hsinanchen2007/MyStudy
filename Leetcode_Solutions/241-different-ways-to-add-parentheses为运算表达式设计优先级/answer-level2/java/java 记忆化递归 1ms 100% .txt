### 思路
- 先将表达式拆分成数字列表`numList`和运算符列表`operatorList`，其中注意的是每个数字的位数可能不止1位；
- 然后，我们发现，当数字个数大于1个的时候，算到最后肯定就剩下两个数字。那么这两个数字，一个肯定是左边若干个数字算出来的结果，另一个则是右边若干个数字算出来的结果。同时，由于不同的括号添加方案，左右都会有多种结果。因此，可的核心算法如下：
```java
        List<Integer> ansList = new ArrayList<>();
        for (int i = start; i < end; i++) {
            List<Integer> leftList = rec(start, i);
            List<Integer> rightList = rec(i + 1, end);
            for (Integer leftNum : leftList) {
                for (Integer rightNum : rightList) {
                    ansList.add(calc(leftNum, rightNum, operatorList.get(i)));
                }
            }
        }
```
其中，`calc`是通过不同的运算符计算两数之间的运算结果。

**完整代码如下：**
```java
private List<Integer> numList;
    private List<Character> operatorList;
    private List<Integer>[][] memo;

    private int calc(int num1, int num2, char operator) {
        switch (operator) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
        }
        return num1 + num2;
    }

    private List<Integer> rec(int start, int end) {
        if (memo[start][end] != null) {
            return memo[start][end];
        }

        if (start == end) {
            memo[start][end] = new ArrayList<>(Collections.singleton(numList.get(start)));
            return memo[start][end];
        }

        List<Integer> ansList = new ArrayList<>();
        for (int i = start; i < end; i++) {
            List<Integer> leftList = rec(start, i);
            List<Integer> rightList = rec(i + 1, end);
            for (Integer leftNum : leftList) {
                for (Integer rightNum : rightList) {
                    ansList.add(calc(leftNum, rightNum, operatorList.get(i)));
                }
            }
        }

        memo[start][end] = ansList;
        return ansList;
    }

    // 拆分成数字和运算符两个数组
    private void splitString(String str) {
        numList = new ArrayList<>();
        operatorList = new ArrayList<>();
        int num = 0;
        for (char c : str.toCharArray()) {
            if (!Character.isDigit(c)) {
                numList.add(num);
                operatorList.add(c);
                num = 0;
            } else {
                num *= 10;
                num += c - '0';
            }
        }

        numList.add(num);
    }

    public List<Integer> diffWaysToCompute(String input) {
        splitString(input);
        int len = numList.size();
        memo = new ArrayList[len][len];
        return rec(0, len - 1);
    }

```