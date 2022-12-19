难道不难。但是要思维严谨一点。
比如以下解法里面，把数字从stack里头拎出来的时候，一定要注意判断栈空和诸如2[4[abc]]这种俩数字连着的情况。
```
class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string resStr;
        
        for (auto ch : s) {
            if (ch == ']') {
                string tmpStr;
                // 出栈直到数字
                while (stk.top() != '[') {
                    tmpStr.push_back(stk.top());
                    stk.pop();
                }
                tmpStr.assign(tmpStr.rbegin(), tmpStr.rend()); // 要记得反转！
                // 出栈出完数字
                stk.pop(); // 出[
                int count = 0, pos = 0; // pos: 位数，乘几个10
                while (!(stk.empty()) && stk.top() != '[' && stk.top() >= '0' && stk.top() <= '9') {
                    // 一定要注意栈空！
                    count += int(stk.top() - '0') * (int)pow((double)10, (double)pos);
                    //printf("%c, count = %d\n", stk.top(), count);
                    pos++;
                    stk.pop();
                }
                // 再次入栈
                int tmpLen = tmpStr.size();
                for (int i = 0; i < count; i++) {
                    for (int j = 0; j < tmpLen; j++) 
                        stk.push(tmpStr[j]);
                }
            } else {
                stk.push(ch);   
            }
        }
        
        while (!stk.empty()) {
            if (stk.top() != '[')
                resStr.push_back(stk.top());
            stk.pop();
        }
        reverse(resStr.begin(), resStr.end());
        return resStr;
    }
};
```