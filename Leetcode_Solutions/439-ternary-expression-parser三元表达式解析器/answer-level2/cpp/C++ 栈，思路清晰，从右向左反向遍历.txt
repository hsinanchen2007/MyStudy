思路：用栈从右向左匹配，遇到?就计算一次结果，并重新推到栈中。相当于不断消除嵌套表达式的过程。

```
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;

        for (int i = expression.length() - 1; i >= 0; i--) {
            if (expression[i] != '?') {
                st.push(expression[i]);
                continue;
            }

            char resTrue = st.top(); //保存true的结果，用于后面判断
            char condition = expression[i - 1]; //保存condition，是T还是F

            // 找到匹配的:号
            while (!st.empty() && st.top() != ':') {
                st.pop();
            }

            st.pop(); //弹出:号
            char resFalse = st.top(); // 获取false的结果
            st.pop(); //弹出condition

            // 按条件计算出对应的值，并压栈以便后续循环计算
            if (condition == 'T') st.push(resTrue);
            else st.push(resFalse);

            i--; //condition已经取出计算了，跳过condition
        }

        string answer;
        answer += st.top();
        return answer;
    }
};
```
