ch数组用于标记字符串中可以匹配的括号，1代表后括号，2代表前括号。
第一个for标记所有可以匹配的后括号的位置，第二个for找到与后括号匹配的前括号位置，第三个while找非零连续序列的最长长度。
第二个for好像是个n^2复杂度的for，所以还得学一手dp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> a;
        int ans = 0;
        short ch[20000]{0};

        //bool * ch = new bool[s.size()]{ 0 };
        for (int i = 0; i<s.size(); i++) {
            if (a.empty()) a.push(s[i]);
            else {
                if (a.top() == '('&&s[i] == ')') {
                    ch[i] = 1;
                    a.pop();
                }
                else {
                    a.push(s[i]);
                }
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            int ind = i - 1;
            if (ch[i] == 1) {
                while (ch[ind] != 0)ind--;
                ch[ind] = 2;
            }
        }
        int maxx = 0;
        int i = 0;
        int tem = 0;
        while (i < s.size()) {
            tem = 0;
            while (ch[i] != 0) i++,tem++;
            i++;
            maxx = tem > maxx ? tem : maxx;
        }
        return maxx;
    }
};