深度优先一个一个字符拼接。第一个拼接的只能是左括号，拼接时，记录当前可拼接右括号数量。
每拼一个左括号，可拼接右括号数量加一，每拼一个右括号，可拼右括号数量减一。
如果左括号拼完了，则只能拼右括号。如果右括号拼完了，则只能拼左括号。如果都有，则都拼。如左右括号都拼完了，则添加结果并结束递归。
```
class Solution {

    List<String> resultList = new ArrayList<>();

    public List<String> generateParenthesis(int n) {

        if (n == 0) {
            return resultList;
        }

        appendNext("(", n - 1, 1);
        return resultList;
    }


    private void appendNext(String val, int leftRest, int needRightNumber) {

        if (leftRest == 0 && needRightNumber == 0) {
            resultList.add(val);
            return;
        }

        // 如果没有左括号了，则只能拼右
        if (leftRest == 0) {
            appendNext(val + ")", leftRest, needRightNumber - 1);
            return;
        }

        // 如果没有右括号了，则只能拼左
        if (needRightNumber == 0) {
            appendNext(val + "(", leftRest - 1, needRightNumber + 1);
            return;
        }

        // 否则都要拼
        appendNext(val + "(", leftRest - 1, needRightNumber + 1);
        appendNext(val + ")", leftRest, needRightNumber - 1);


    }
```
