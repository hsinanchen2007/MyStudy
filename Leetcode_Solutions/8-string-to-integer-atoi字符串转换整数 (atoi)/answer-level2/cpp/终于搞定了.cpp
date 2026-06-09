class Solution {
public:
    int myAtoi(string str)
    {
        // 处理第一个+和-
        int pos(0);
        bool positive(true);
        while (str[pos] == ' ') {
            pos++;
        }
        if (str[pos] == '-' || str[pos] == '+') {
            positive = (str[pos] == '+');
            pos++;
        }

        // 开始计算
        int res(0);
        while (str[pos]) {
            if (str[pos] < '0' || str[pos] > '9'){
                break;
            }
            int val = str[pos] - '0';
            if (positive) {
                if (res <= (INT_MAX - val) / 10) {
                    res = res * 10 + val;
                } else {
                    return INT_MAX;
                }
            } else {
                if (res >= (INT_MIN + val) / 10) {
                    res = res * 10 - val;
                } else {
                    return INT_MIN;
                }
            }
            pos++;
        }
        return res;
    }
};