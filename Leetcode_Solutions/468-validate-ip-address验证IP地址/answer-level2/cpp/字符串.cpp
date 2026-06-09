### 解题思路
注意细节

### 代码

```cpp
class Solution {
public:

bool IsTenDigital(string numStr)
{
	if (numStr.empty()) {
		return false;
	}
	for (auto chrNum : numStr) {
		if (chrNum < '0' || chrNum > '9') {
			return false;
		}
	}
	return true;
}

bool JudgeIpv4(string IP, int& startIndex, int i)
{
	if (i - startIndex > 3 || i - startIndex <= 0) {
		return false;
	}
	string numStr = IP.substr(startIndex, i - startIndex);
	cout << numStr << endl;
	if (IsTenDigital(numStr)) {
		if ((numStr.size() == 1) || (numStr[0] != '0' && stoi(numStr) <= 255)) {
			startIndex = i + 1;
		} else {
			return false;
		}
	} else {
		return false;
	}
	return true;
}

bool IsIPV4(string IP)
{
	int startIndex = 0;
	int dotsNum = 0;
	for (int i = 0; i < IP.size(); i++) {
		if (IP[i] == '.') {
			dotsNum++;
			if (! JudgeIpv4(IP, startIndex, i)) {
				return false;
			}
		}
	}
	if (! JudgeIpv4(IP, startIndex, IP.size())) {
		return false;
	}
	return dotsNum == 3 ? true : false;
}

bool IsHexDigital(string numStr)
{
	for (auto chrNum : numStr) {
		if ((chrNum >= '0' && chrNum <= '9') ||
			(chrNum >= 'a' && chrNum <= 'f') ||
			(chrNum >= 'A' && chrNum <= 'F')) {
				continue;
			} else {
				return false;
			}
	}
	return true;
}

bool JudgeIpv6(string IP, int& startIndex, int i)
{
	if (i - startIndex <= 0 || i - startIndex > 4) {
		return false;
	}
	
	string numStr = IP.substr(startIndex, i - startIndex);
	if (IsHexDigital(numStr)) {
		startIndex = i + 1;
	} else {
		return false;
	}
	return true;
}

bool IsIPV6(string IP)
{
	int startIndex = 0;
	int dotsNum = 0;
	for (int i = 0; i < IP.size(); i++) {
		if (IP[i] == ':') {
			dotsNum++;
			if (! JudgeIpv6(IP, startIndex, i)) {
				return false;
			}
		}
	}
	if (! JudgeIpv6(IP, startIndex, IP.size())) {
		return false;
	}
	return dotsNum == 7 ? true : false;
}

string validIPAddress(string IP) {
	if (IsIPV4(IP)) {
		return "IPv4";
	}
	if (IsIPV6(IP)) {
		return "IPv6";
	}
	return "Neither";
}
};
```