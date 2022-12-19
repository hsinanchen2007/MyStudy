1. 将 0 写成 n 个0的字符串
2. 每次修改一位，如将"0000"改为"1000"，并置其访问标记为真
3. 回溯，直到所有数都被访问过
```
class Solution {
public:
    int length;
    vector<int> ans;
    vector<int> sign;   // 是否被访问标志
    bool over = false;  // 是否结束标志
    int B2D(string s) { // 二进制转换为十进制
        int sum = 0;
        int root = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            int num = s[i] - '0';
            sum += num * root;
            root *= 2;
        }
        return sum;
    }

    char NOT(char c) { // 取反
        char code = c - '0';
        code = (code == 1) ? 0 : 1;
        c = '0' + code;
        return c;
    }

    void backtrack(string s, int n) {// 回溯算法
        // 如果被访问过，返回
        if (sign[B2D(s)] == 1) return;
        sign[B2D(s)] = 1;
        for (int i = 0; i < s.size(); i++) {
            ans.push_back(B2D(s));
            s[i] = NOT(s[i]);
            // 如果结束 ，置结束标记为真，返回
            if (n == length) {
                over = true;
                return;
            }
            backtrack(s, n + 1);
            //如果结束，跳出循环
            if (over) break;
            s[i] = NOT(s[i]);
            ans.pop_back();
        }
        sign[B2D(s)] = 0;
    }
    vector<int> grayCode(int n) {
        if (n == 0) return{ 0 };
        length = pow(2, n) - 1;
        vector<int> sign(length + 1, 0);
        this->sign = sign;
        string code = "";
        code.assign(n, '0');
        backtrack(code, 0);
        return ans;
    }
};
```
