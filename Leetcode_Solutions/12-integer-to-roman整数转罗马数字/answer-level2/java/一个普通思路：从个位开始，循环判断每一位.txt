### 解题思路
此处撰写解题思路
    我还没看大佬们的解题思路，本人刷题少，第一次看到这个题，就先从个位下手
    共有以下几种情况
        **
        1、数字4
        2、数字9
        3、数字x < 4
        4、数字x > 5
        5、数字5
        **

    然后考虑罗马字母有两类，姑且称为：
        5类：  , V, L, D
        10类: I, X, C, M
    两类一一对应就是下面的这两个数组（之后当前索引 j 所在位置称为"本级"，j+1称为"下一级", 每一级罗马字母是上一级的10倍）
```
        String level_5[] = {"", "V", "L", "D"};
        String level_10[] = {"I", "X", "C", "M"};
```
    然后从个位开始到最高位结束，每循环一次，让 num /= 10， 即算下一位，
        情况1、本级10类 + 下一级5类组合
        情况2、本级10类 + 下一级10类组合
        情况3、余数的个数 * 本级10类组合
        情况4、下一级5类 + 余数的个数 * 本级10类
        情况5、下一级5类


    每一位结果顺序存放在e:String[]数组中，
    最后反向拼接打印出来

        



### 代码

```java
class Solution {
    public String intToRoman(int num) {
        String level_5[] = {"", "V", "L", "D"};
        String level_10[] = {"I", "X", "C", "M"};
        String e[] = {"", "", "", "", ""};
        int j = 1;
        while (num != 0) {
            if (num % 10 == 4) {
                e[j] = level_10[j - 1] + level_5[j];
            } else if (num % 10 == 9) {
                e[j] = level_10[j - 1] + level_10[j];
            } else {
                if (num % 10 < 4) {
                    for (int i = 0; i < (num % 10); i++) {
                        e[j] += level_10[j - 1];
                    }
                } else if (num % 10 > 5) {
                    e[j] = level_5[j];
                    for (int i = 0; i < (num % 10) - 5; i++) {
                        e[j] += level_10[j - 1];
                    }
                } else if (num % 10 == 5) {
                    e[j] += level_5[j];
                }
            }
            num /= 10;
            j++;
        }
        String rst = "";
        for (int i = e.length - 1; i >= 0; i--) {
            rst += e[i];
        }
        return rst;
    }
}
```