```c++
class Solution {
public:
    unsigned int ipToInt(string &str) {
        unsigned int sum = 0;
        int num = 0;
        str += '.';
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            if (str[i] == '.') {
                sum = sum * 256 + num;
                num = 0;
            } else {
                num = 10 * num + str[i] - 48;
            }
        }
        return sum;
    }

    string intToIp(unsigned int num, int k) {
        stringstream ss;
        int a[4];
        int i = 4;
        while (i--) {
            a[i] = num % 256;
            num /= 256;
        }
        for (i = 0; i < 3; ++i) {
            ss << a[i] << ".";
        }
        int tmp = -1;
        while (k) {
            k /= 2;
            tmp++;
        }
        ss << a[3] << "/" << 32 - tmp;
        return ss.str();
    }

    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        unsigned int num = ipToInt(ip);
        while (true) {
            unsigned int k = num & (-num);
            while (k > n) {
                k /= 2;
            }
            n -= k;
            res.push_back(intToIp(num, k));
            if (n > 0) {
                num += k;
            } else {
                break;
            }
        }
        return res;
    }
};