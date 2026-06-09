// 先切割，然后独自判断
class Solution {
public:
    string validIPAddress(string IP) {
        if (validIPv4(IP)) {
            return "IPv4";
        } else if (validIPv6(IP)) {
            return "IPv6";
        } else {
            return "Neither";
        }
    }

    vector<string> split(const string &str, char delim) {
        vector<string> elements;
        vector<int> positions;
        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (c == delim) {
                positions.push_back(i);
            }
        }
        if (positions.size() == 0) {
            elements.push_back(str);
            return elements;
        }
        vector<int> lengths;
        int length = 0;
        for (int i = 0; i < positions.size(); i++) {
            int pos = positions[i];
            if (i == 0) {
                length = pos;
            } else {
                length = pos - positions[i - 1] - 1;
            }
            lengths.push_back(length);
        }
        length = str.size() - 1 - positions[positions.size() - 1];
        lengths.push_back(length);
        string strItem;
        for (int i = 0; i < lengths.size(); i++) {
            int length = lengths[i];
            if (length == 0) {
                strItem = "";
            } else {
                if (i == 0) {
                    strItem = str.substr(0, length);
                } else {
                    strItem = str.substr(positions[i - 1] + 1, length);
                }
            }
            elements.push_back(strItem);
        }
        return elements;
    }

    bool validIPv4(const string &str) {
        vector<string> elements = split(str, '.');
        if (elements.size() != 4) {
            return false;
        }
        for (int i = 0; i < elements.size(); i++) {
            string ip = elements[i];
            if (ip.size() == 0 || ip.size() > 3) {
                return false;
            }
            for (int j = 0; j < ip.size(); j++) {
                char c = ip[j];
                if (!validIPv4Char(c)) {
                    return false;
                }
            }
            if (ip.size() > 1 && ip[0] == '0') {
                return false;
            }
            int val = stoi(ip);
            if (val < 0 || val > 255) {
                return false;
            }
        }
        return true;
    }

    bool validIPv6(const string &str) {
        vector<string> elements = split(str, ':');
        if (elements.size() != 8) {
            return false;
        }
        for (int i = 0; i < elements.size(); i++) {
            string ip = elements[i];
            if (ip.size() == 0 || ip.size() > 4) {
                return false;
            }
            for (int j = 0; j < ip.size(); j++) {
                char c = ip[j];
                if (!validIPv6Char(c)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validIPv4Char(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }

    bool validIPv6Char(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        if (c >= 'A' && c <= 'F') {
            return true;
        }
        if (c >= 'a' && c <= 'f') {
            return true;
        }
        return false;
    }
};