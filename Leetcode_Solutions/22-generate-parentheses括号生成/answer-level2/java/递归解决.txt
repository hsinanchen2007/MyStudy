### 解题思路
思路：使用递归方法寻找所有可能性

1.假设当前位置为i，已使用左括号数为l,已使用右括号数为r
分3种情况：
(1) l为n，即左括号已使用完，则将右括号填充完毕，并填充进list中，递归结束
(2) l不为n，且l = r，说明左右括号配对使用，接下来位置i+1只能填充左括号，填充左括号后，进行i+2位置判断
(3) l不为n，且l>r，说明左侧存在未配对的左括号，则接下来位置i+1可填充左括号，或填充右括号，分2种情况进行递归即可

### 代码

```java
class Solution {
    List<String> parenthesis = new ArrayList<>();

    int length;

    public List<String> generateParenthesis(int n) {
        length = n;
        addParenthesis("(", 1, 0);

        return parenthesis;
    }

    private void addParenthesis(String current, int usedLeftParenthesis, int usedRightParenthesis) {
        if (usedLeftParenthesis == length) {
            StringBuilder currentBuilder = new StringBuilder(current);
            while (usedRightParenthesis != length) {
                currentBuilder.append(")");
                usedRightParenthesis++;
            }
            current = currentBuilder.toString();
            parenthesis.add(current);
            return;
        }

        addParenthesis(current + "(", usedLeftParenthesis + 1, usedRightParenthesis);
        if (usedRightParenthesis < usedLeftParenthesis) {
            addParenthesis(current + ")", usedLeftParenthesis, usedRightParenthesis + 1);
        }
    }
}
```