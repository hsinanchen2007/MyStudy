```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int strLen = tokens.size();
        int loop;
        int currVal, currVal1, currVal2;
        stack<int> stackList;
        for (loop = 0; loop < strLen; loop++) {
            string str = tokens[loop];
            if ((str != "+") && (str != "-") && (str != "*") && (str != "/")) {
                currVal = stoi(str);
                stackList.push(currVal);
                continue;
            }
            
            if (!stackList.empty()) {
                currVal2 = stackList.top();
                stackList.pop();
                currVal1 = stackList.top();
                stackList.pop();
                if (str == "+") {
                    currVal = currVal1 + currVal2;
                } else if (str == "-") {
                    currVal = currVal1 - currVal2;
                } else if (str == "*") {
                    currVal = currVal1 * currVal2;
                } else if (str == "/") {
                    currVal = currVal1 / currVal2;
                }

                stackList.push(currVal);
            }
        }

        return stackList.top();
    }
};
```
