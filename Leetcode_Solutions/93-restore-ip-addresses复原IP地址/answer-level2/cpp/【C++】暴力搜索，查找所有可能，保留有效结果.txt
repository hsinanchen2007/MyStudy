```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/19
 */

struct IpAddressRaw {
    string input;
    string ip;
    int dots;
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        const int minIpLength = 4;
        const int maxIpLength = 12;
        if (s.size() < minIpLength || s.size() > maxIpLength) {
            return vector<string>();
        }
        return restoreIpAddressesBfs(s);
    }

private:
    vector<string> restoreIpAddressesBfs(string s)
    {
        vector<string> results;
        queue<IpAddressRaw> checkQueue;
        IpAddressRaw ipAddressRaw;
        ipAddressRaw.dots = 0;
        ipAddressRaw.ip = "";
        ipAddressRaw.input = s;

        checkQueue.push(ipAddressRaw);
        while (!checkQueue.empty()) {
            IpAddressRaw current = checkQueue.front();
            checkQueue.pop();
            if (current.dots == 3) {
                if (current.input.empty()) {
                    results.push_back(current.ip);
                }
            } else {
                for (int i = 1; i <= 3; i++) {
                    if (current.input.length() >= i) {
                        IpAddressRaw next = current;
                        stringstream ss;
                        ss << next.input.substr(0, i);
                        int data = 0;
                        ss >> data;
                        ss.clear();
                        ss.str("");
                        ss << data;
                        if (next.input.substr(0, i) == ss.str()) {
                            if (data >= 0 && data <= 255) {
                                if (next.ip.empty()) {
                                    next.ip += next.input.substr(0, i);
                                } else {
                                    next.ip += ".";
                                    next.ip += next.input.substr(0, i);
                                    next.dots += 1;
                                }
                                next.input = next.input.substr(i);
                                checkQueue.push(next);
                            }
                        }
                    }
                }
            }
        }
        return results;
    }
};
```
