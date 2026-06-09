### 解题思路
采用人工计算形式。。。从低位开始相加计算
最后要注意最后一次进位，还要加1

### 代码

```cpp
using uchar = unsigned char;
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }
        string result;
        int posa = a.size() - 1;
        int posb = b.size() - 1;
        int carry = 0;
        int ucb = 0;
        int uca = 0;
        while ((posa >= 0) || (posb >= 0)) {
            if (posa >= 0) {
                uca = a[posa] - '0';
            } else {
                uca = 0;
            }
            if (posb >= 0) {
                ucb = b[posb] - '0';
            } else {
                ucb = 0;
            }
            //cout << uca << "---" << ucb << "---" << carry << endl;
            int tmp = cal(uca + ucb + carry, carry);
            //cout << "tmp---" << tmp << " carry---" << carry << endl;;
            result.insert(0, 1, '0' + (uchar)tmp);
            //cout << "result" << result << endl;
            --posa;
            --posb;
        }
       if (carry == 1) {
           result.insert(0, 1, '1');
       }
        return result;
    }
    int cal(int input, int& carry) {
        if (input == 0) {
            carry = 0;
            return 0;
        } else if (input == 1) {
            carry = 0;
            return 1;
        } else if (input == 2) {
            carry = 1;
            return 0;
        } else if (input == 3){
            carry = 1;
            return 1;
        } else {
            cout << "input is ERR:" << input << endl;
        }
        return 0;
    }
};
```