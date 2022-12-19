1.计算没有括号的表达式
2.使用stack计算有括号的表达式，括号内的表达式使用1的方式计算
3.在括号的场景下有1-(2-3) 中间结果是1--1，replace -- 为+，稍微调整了下，记录下
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/10/09
*/

class Solution {
public:
    int calculate(string s)
    {
        stack<string> subExpression;
        stack<char> ops;

        stringstream ss;
        for (string::const_iterator iter = s.begin();
                iter != s.end();
                ++iter) {
            if (*iter == '(') {
                if (!ss.str().empty()) {
                    cout << "exp:" << ss.str() << endl;
                    subExpression.push(ss.str());
                    ss.str("");
                }
                ops.push(*iter);
            } else if (*iter == ')') {
                string expression = ss.str();
                replaceSubSubToAdd(expression);
                int data = calculateAddSub(expression);
                ss.str("");
                if (!subExpression.empty()) {
                    ss << subExpression.top();
                    subExpression.pop();
                    ss << data;
                } else {
                    ss << data;
                }
                ops.pop();
            } else {
                ss << *iter;
            }
        }
        if (!ss.str().empty()) {
            subExpression.push(ss.str());
            ss.clear();
        }

        return buildResult(subExpression);
    }

    void replaceSubSubToAdd(string &expression)
    {
        std::size_t pos = expression.find("--");
        while (pos != string::npos) {
            expression = expression.replace(pos, 2, "+");
            pos = expression.find("--");
        }
    }

    int buildResult(stack<string> &subExpression)
    {
        string expression = subExpression.empty() ? "" : subExpression.top();
        replaceSubSubToAdd(expression);
        int result = (subExpression.empty() ? 0 : calculateAddSub(expression));
        return result;
    }

    int calculateAddSub(string const &s)
    {
        cout << "calculateAddSub s:" << s << endl;
        stack<int> datas;
        stack<char> ops;

        stringstream ss;
        for (string::const_iterator iter = s.begin();
                iter != s.end();
                ++iter) {
            if (*iter == ' ') {
                continue;
            }

            if (*iter == '+' || *iter == '-') {
                calculateAddSub(ss, datas, ops);
                ops.push(*iter);
            } else {
                ss << *iter;
            }
        }
        calculateAddSub(ss, datas, ops);

        return datas.empty() ? 0 : datas.top();
    }

    void calculateAddSub(stringstream &ss, stack<int> &datas, stack<char> &ops)
    {
        if (!ss.str().empty()) {
            int data = 0;
            ss >> data;
            datas.push(data);
            ss.clear();
            ss.str("");
            if (!ops.empty() && datas.size() >= 2) {
                char op = ops.top();
                addSubTwoData(op, datas);
                ops.pop();
            } else if (!ops.empty() && datas.size() == 1) {
                char op = ops.top();
                addSubOneData(op, datas);
                ops.pop();
            }
        }
    }

    void addSubOneData(char op, stack<int> &datas)
    {
        if (op == '+') {
            int one = datas.top();
            int result = one;
            datas.push(result);
        } else if (op == '-') {
            int one = datas.top();
            datas.pop();
            int result = -one;
            datas.push(result);
        }
    }

    void addSubTwoData(char op, stack<int> &datas)
    {
        if (op == '+') {
            int one = datas.top();
            datas.pop();
            int another = datas.top();
            datas.pop();
            int result = another + one;
            datas.push(result);
        } else if (op == '-') {
            int one = datas.top();
            datas.pop();
            int another = datas.top();
            datas.pop();
            int result = another - one;
            datas.push(result);
        }
    }

};
```
