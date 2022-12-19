```c++
class Solution {
public:
    string getSimilar(string str) {
        int num = hexToInt(str);
        int min = 1000;
        string minStr;
        for (int i = -1; i <= 1; ++i) {
            if (i == -1 && str[0] == '0') {
                continue;
            }
            if (i == 1 && str[0] == 'f') {
                continue;
            }
            string tmp = str;
            char c = str[0] + i;
            if (c > '9' && c < 'a') {
                if (i == 1) {
                    c = 'a';
                } else {
                    c = '9';
                }
            }
            tmp[0] = tmp[1] = c;
            int tmpNum = abs(hexToInt(tmp) - num);
            if (tmpNum < min) {
                min = tmpNum;
                minStr = tmp;
            }
        }
        return minStr;
    }

    int hexToInt(string &str) {
        int num = 0;
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            if (isalpha(str[i])) {
                num = num * 16 + str[i] - 87;
            } else {
                num = num * 16 + str[i] - 48;
            }
        }
        return num;
    }

    string similarRGB(string color) {
        return "#" + getSimilar(color.substr(1, 2)) + getSimilar(color.substr(3, 2)) + getSimilar(color.substr(5, 2));
    }
};