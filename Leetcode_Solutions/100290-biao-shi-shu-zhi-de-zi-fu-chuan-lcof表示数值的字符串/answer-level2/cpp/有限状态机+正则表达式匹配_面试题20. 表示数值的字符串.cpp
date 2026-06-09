### 解题思路一 有限状态机
    /*
     * 方法1 有限状态机(DFA)
     * 可通过编译原理中的有限状态机DFA解决，
     * 首先通过正则表达式构建DFA图(有限状态机.png)
     * ^\s*[\+\-]?(\d+\\.?\d*|\\.\d+)([eE][\+\-]?\d+)?\s*$
     * 再根据有限状态机的走向进行状态判断，
     * state表示遍历时的状态，flag处理特殊的 . ，
     * WARNing : 要去除字符串首尾可能存在的空字符
     * */
![有限状态机.png](https://pic.leetcode-cn.com/f9133b624ab760f84c3356813cadc6a22add0568c05955c522e9fc04507190b7-%E6%9C%89%E9%99%90%E7%8A%B6%E6%80%81%E6%9C%BA.png)

### 代码

```cpp
bool isNumber(std::string s) {
    int state = 0, flag = 0;
    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    while (s[s.size() - 1] == ' ') {
        s.erase(s.size() - 1, 1);
    }

    if (s.empty()) {
        return false;
    }

    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            flag = 1;
            if (state <= 2) {
                state = 2;
            } else if (state <= 5) {
                state = 5;
            } else {
                state = 7;
            }
        } else if (s[i] == '+' || s[i] == '-') {
            if (state == 0 || state == 3) {
                state++;
            } else {
                return false;
            }
        } else if (s[i] == '.') {
            if (state <= 2) {
                state = 6;
            } else {
                return false;
            }
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (flag && (state == 2 || state == 6 || state == 7)) {
                state = 3;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return (state == 2 || state == 5 || (flag && state == 6) || state == 7);
}
```
### 解题思路二 正则表达式
    /*
     * 方法2 正则表达式
     * 测试正则表达式的网址： https://ihateregex.io/playground
     * 匹配模式 ^\s*[\+\-]?(\d+\.?\d*|\.\d+)([eE][\+\-]?\d+)?\s*$
     * 有限状态机的状态图是从正则表达式中推出的，
     * 所以正则表达式可以解决
     * */
### 代码

```cpp
bool isNumber2(std::string s) {
    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    while (s[s.size() - 1] == ' ') {
        s.erase(s.size() - 1, 1);
    }

    if (s.empty()) {
        return false;
    }

    std::regex re(R"(^[\+\-]?(\d+\.\d+|\.\d+|\d+\.|\d+)(e[\+\-]?\d+)?$)");

    return std::regex_match(s, re);
}
```

### 解题思路三
    /*
     * 方法3 逐一判断
     * 遍历字符串，逐一判断每个字符是否满足条件，
     * 如果不满足返回false，满足继续往下判断
     * 可能会有想不到的条件，不可取
     * */
