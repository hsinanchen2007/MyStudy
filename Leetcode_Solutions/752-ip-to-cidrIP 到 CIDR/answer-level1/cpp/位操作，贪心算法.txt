### 解题思路
一开始没想明白，后来参考了一位用c语言解题的同学的思路，用c++写了一遍

### 代码

```cpp
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        unsigned int ipInt = ip2int(ip);
        vector<string> result;

        while (n > 0) {
            unsigned int lowBitOne = ipInt & ((-1) * ipInt);

            unsigned int mask = 32;

            while (lowBitOne > n) {
                lowBitOne >>= 1;
            }

            int temp = lowBitOne;
            while (temp > 1) {
                temp >>= 1;
                mask -= 1;
            }

            result.push_back(int2ip(ipInt, mask));

            ipInt += lowBitOne;
            n -= lowBitOne;
        }

        return result;
    }
private:
    unsigned int ip2int(string ip)
    {
        stringstream ss(ip);
        string s;
        unsigned int answer = 0;

        while (getline(ss, s, '.')) {
            answer += answer * 255 + stoi(s);
        }

        return answer;
    }

    string int2ip(unsigned int ip, int mask)
    {
        vector<string> str;

        for (int i = 0; i < 4; ++i) {
            str.push_back(to_string(ip & 0xFF));
            ip >>= 8;
        }

        string answer;
        for (int i = 3; i >= 0; --i) {
            answer += str[i] + ".";
        }
        answer.pop_back();

        answer += "/" + to_string(mask);

        return answer;
    }
};
```