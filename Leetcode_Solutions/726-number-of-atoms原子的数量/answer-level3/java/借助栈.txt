栈放数字
```
class Solution {
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = new TreeMap<>();
        Stack<Integer> num = new Stack<>();
        int curNum = 1; // 当前遍历到的数字
        String numStr = null; // 当前遍历到的数字字符串
        String curStr = null; // 当前遍历到的元素字符串
        for (int i = formula.length() - 1; i >= 0; i--) {
            char curChar = formula.charAt(i);
            if (curChar == '(') { // 当前字符为左括号
                num.pop(); // 数字出栈
            } else if (Character.isLowerCase(curChar)) { // 当前字符为小写字符
                curStr = String.valueOf(curChar); // 保存
            } else if (Character.isDigit(curChar)) { // 当前字符为数字
                if (numStr != null) {
                    numStr = String.valueOf(curChar) + numStr;
                } else {
                    numStr = String.valueOf(curChar);
                }
                if (!Character.isDigit(formula.charAt(i - 1))) { // 数字位数大于1
                    if (num.isEmpty()) {
                        num.push(Integer.valueOf(numStr));
                    } else {
                        num.push(num.peek() * Integer.valueOf(numStr));
                    }
                    numStr = null; // 更新
                }
            } else if (Character.isUpperCase(curChar)) { //当前字符为大写字符
                if (curStr != null) {
                    curStr = String.valueOf(curChar) + curStr;
                } else {
                    curStr = String.valueOf(curChar);
                }
                if (!num.isEmpty() && 
                    (Character.isDigit(formula.charAt(i + 1)) || (Character.isDigit(formula.charAt(i + 2)) && Character.isLowerCase(formula.charAt(i + 1))))) {
                    curNum = num.pop(); // (OH2)2和(Mg2)2 若字母后紧跟数字，则数字出栈
                } else if (!num.isEmpty()) {
                    curNum = num.peek(); // (OH)2 若字母后紧跟右括号，则取出栈顶
                }

                if (!map.containsKey(String.valueOf(curStr))) {
                    map.put(curStr, curNum);
                } else {
                    map.put(curStr, map.get(curStr) + curNum);
                }
                curStr = null;
                curNum = 1;
            }
        }

        StringBuilder sb = new StringBuilder("");
        for (String key : map.keySet()) {
            sb.append(key);
            if (map.get(key) != 1) {
                sb.append(map.get(key));
            }
        }
        return sb.toString();
    }
}
```

