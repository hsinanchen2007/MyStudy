### 解题思路
题干中两个关键信息，一是从右向左匹配，二是存在循环嵌套。所以，关键是如何找到满足可以计算完整表达式的条件。
这里的方法是通过观察三目运算符中"？"和"："的出现规律。":"和其左边相邻的第一个"?"必然是成对的，如果":"出现之后，左边紧接着出现的第一个运算符不是"?"，而是":"，说明出现嵌套。
基于这个规律，采用一个计数器，当遇到":"则加一，当遇到"?"则减一，计数器为0并且左值和右值都不为空，说明找到了一条完整表达式。直接计算出结果，重新把结果入栈，直到所有的表达式都被计算完毕。


### 代码

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        string res;

        string falseAns;
        string trueAns;
        char tempEle;
        int isCompleteExpression = 0;

        while (!expression.empty()) {
            tempEle = expression.back();
            expression.pop_back();

            //判断是否已经找到一条完整表达式
            if ((tempEle == 'T' || tempEle == 'F')&& !falseAns.empty() && !trueAns.empty() && !isCompleteExpression) {
                res = (tempEle == 'T') ? trueAns : falseAns;
                trueAns.clear();
                falseAns.clear();
                //如果剩余表达式不为空，或当前表达式的计算结果不是最终值，则将结果重新入栈
                if (expression.length() > 0 || res.length() > 0) {
                    expression += res;
                }
                continue;
            } else if (tempEle == '?') {
                // 计数器减一后，结果不为0，说明当前的"?"是嵌套表达式的一部分，需要加回到左值中
                if (--isCompleteExpression > 0) {
                    trueAns = tempEle + trueAns;
                }
            } else if (tempEle == ':') {
                 // 同上，符号是嵌套表达式的一部分
                if (++isCompleteExpression > 1) {
                    trueAns = tempEle + trueAns;
                }
            } else if (falseAns.empty()|| falseAns == ""){
                falseAns = tempEle + falseAns;
            } else {
                trueAns = tempEle + trueAns;
            }
        }

        return res;
    }
};
```