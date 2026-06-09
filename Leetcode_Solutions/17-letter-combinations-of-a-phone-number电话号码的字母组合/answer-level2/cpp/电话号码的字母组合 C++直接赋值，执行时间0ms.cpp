思路：遍历输入的数字，每添加一个数字，即是将之前结果的每一个字符串进行扩增，如例子“23”：
第一个数字2，直接生成单字母的字符串：{"a","b","c"}；
第二个数字3，对之前结果（共3个字符串）的每一个字符串进行扩充：
(1)对字符串"a"扩充，加上{'d', 'e', 'f'}，得到3个字符串{"ad","ae","af"}，将其添加进行结果中
(2)对字符串"b"扩充，加上{'d', 'e', 'f'}，得到3个字符串{"bd","be","bf"}，将其添加进行结果中
(3)对字符串"c"扩充，加上{'d', 'e', 'f'}，得到3个字符串{"cd","ce","cf"}，将其添加进行结果中
...依次类推

class Solution {
public:
    const vector<char> g_Char[8] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for (int i = 0; i < digits.length(); i++) {
            int charIdx = digits[i] - '2';
            if (i == 0) {
                for (int j = 0; j < g_Char[charIdx].size(); j++) {
                    string cur;
                    cur += g_Char[charIdx].at(j);
                    result.push_back(cur);
                }
            } else {
                int curStrNum = result.size();
                for (int j = 0; j < curStrNum; j++) {
                    for (int k = 1; k < g_Char[charIdx].size(); k++) {
                        string cur = result[j] + g_Char[charIdx][k];
                        result.push_back(cur);
                    }
                    result[j] += g_Char[charIdx][0];
                }
            }
        }

        return result;
    }
};