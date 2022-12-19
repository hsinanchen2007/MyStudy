对整个三元组构成的树进行遍历，代码如下所示：
```
#include <string.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* 
F?T?2:5:T?2:7
*/


class Solution {
public:
    int cnt = 0;
    string getValue(string & expr) {
        // if (cnt == expr.size() -1) return expr[cnt];
        if (cnt == expr.size() -1) {
            string x = "";
            x += expr[cnt];
            return x;
        }
        if (expr[cnt] == 'F' && expr[cnt+1] == '?') {
            cnt++;
            cnt++;
            getValue(expr);
            cnt++;
            cnt++;
            return getValue(expr);
        } else if (expr[cnt] == 'T' && expr[cnt+1] == '?') {
            cnt++;
            cnt++;
            string x = getValue(expr);
            cnt++;
            cnt++;
            getValue(expr);
            return x;
        } else {
            string x = "";
            x += expr[cnt];
            return x;
            // return expr[cnt];
        }
    }
    string parseTernary(string expression) {
        string x = getValue(expression);
        return x;
    }
};
```