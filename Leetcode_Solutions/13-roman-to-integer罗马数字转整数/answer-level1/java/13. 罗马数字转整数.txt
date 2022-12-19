![image.png](https://pic.leetcode-cn.com/c80f85b0f648c16c14ffb8a5075f1ba921ec3e243bb0a21c00e49d92df9b2bec-image.png)
思路：
选择用switch映射对应值，处理六种特殊情况
代码：
```
class Solution {
    public int romanToInt(String s) {
       char[] targetCharacters = s.toCharArray();
        int index = 0, value = 0, sum = 0;
        while (index < targetCharacters.length) {
            switch (targetCharacters[index]) {
                case 'I':
                    ///default
                    value = 1;
                    if (index != targetCharacters.length - 1) {
                        if (targetCharacters[index + 1] == 'V') {
                            value = 4;
                            index++;
                        } else if (targetCharacters[index + 1] == 'X') {
                            value = 9;
                            index++;
                        }
                    }
                    break;
                case 'X':
                    ///default
                    value = 10;
                    if (index != targetCharacters.length - 1) {
                        if (targetCharacters[index + 1] == 'L') {
                            value = 40;
                            index++;
                        } else if (targetCharacters[index + 1] == 'C') {
                            value = 90;
                            index++;
                        }
                    }
                    break;
                case 'C':
                    ///default
                    value = 100;
                    if (index != targetCharacters.length - 1) {
                        if (targetCharacters[index + 1] == 'D') {
                            value = 400;
                            index++;
                        } else if (targetCharacters[index + 1] == 'M') {
                            value = 900;
                            index++;
                        }
                    }
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'L':
                    value = 50;
                    break;
                case 'D':
                    value = 500;
                    break;
                case 'M':
                    value = 1000;
                    break;
                default:
                    System.out.println("default.");
                    break;
            }
            index++;
            sum += value;
        }
        return sum;
    }
}

```
