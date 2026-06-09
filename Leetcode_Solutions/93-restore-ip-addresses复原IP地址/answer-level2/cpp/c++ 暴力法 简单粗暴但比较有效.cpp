暴力解法，
通过三层for循环，每层循环代表IP地址中1个“.”，遍历3个点所有可能的位置，
对每种可能的场景分别获取其对应的IP地址字符串，
字符串中每个IP地址数字均符合要求则将该字符串加入结果列表中。

```
class Solution {
public:
    static bool isValid(string &s)
    {
        if (s == "0") {
            return true;
        }

        int size = s.length();
        int value = atoi(s.c_str());      
	    
        int count = 0;
        while (value != 0) {
            count++;
            value = value / 10;
        }

        return size == count;
    }

    static void GetIpString(int i, int j, int k, string &s, vector<string> &vec)
    {
        if (i + j + k >= s.length()) {
            return;
        }
        string tmp = "";

        string one = s.substr(0, i);
        if (!isValid(one) || atoi(one.c_str()) > 255) {
            return;
        } else {
            tmp += one + ".";
        }

        string two = s.substr(i, j);
        if (!isValid(two) || atoi(two.c_str()) > 255) {
            return;
        } else {
            tmp += two + ".";
        }

        string three = s.substr(i + j, k);
        if (!isValid(three) || atoi(three.c_str()) > 255) {
            return;
        } else {
            tmp += three + ".";
        }

        string four = s.substr(i + j + k, s.length() - (i + j + k));
        if (!isValid(four) || atoi(four.c_str()) > 255) {
            return;
        } else {
            tmp += four;
            vec.push_back(tmp);
        }
	
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> vec;
        if (s.length() < 4 || s.length() > 12) {
            return vec;
        }

        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                for (int k = 1; k < 4; ++k) {
                    GetIpString(i, j, k, s, vec);
                }
            }
        }

        return vec;
    }
};
```