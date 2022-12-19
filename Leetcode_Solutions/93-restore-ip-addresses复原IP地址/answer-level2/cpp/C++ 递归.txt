1.获取合理第分割子串， 0 - 255 逐步填充分割符‘.’，
2.递归计算剩余子串，
3.当填充到第3个分割符后，递归结束。判断合理子串并保存结果。 

```
void getIpAddr(string ip, string s, vector<string> &ipAddrs) {
    int num = count(ip.begin(), ip.end(), '.');
    if (num == 3) {
        if (s.length() <= 3 && s.length() > 0) {
            if (s[0] == '0' && s.length() > 1) {
                return;
            }
            if (stoi(s, nullptr) <= 255) {
                ip = ip + s;
                ipAddrs.push_back(ip);
            }
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (s.length() < i) {
            return;
        }
        string slice = s.substr(0, i);
        if (slice[0] == '0' && i > 1) {
            return;
        }
        if (stoi(slice, nullptr) <= 255) {
            string tmpIp = ip + s.substr(0, i) + ".";
            getIpAddr(tmpIp, s.substr(i), ipAddrs);
        }

    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ipAdrrs;
    if (s.length() > 12 || s.length() < 4) {
        return ipAdrrs;
    }
    string ip = "";
    getIpAddr(ip, s, ipAdrrs);
    return ipAdrrs;
}

```
