class Solution {
public:
    Solution() : len(0)
    {}
    void getString(vector<string>& output, string cur, int pos)
    {
        if (pos == len) {
            output.push_back(cur);
            return;
        }
        int index = input[pos] - '0';
        string tempStr = table[index];
        for (int i = 0; i < tempStr.size(); i++) {
            getString(output, cur + tempStr[i], pos + 1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> output;
        if (digits.size() == 0) {
            return output;
        }
        table.assign({"", "", "abc", "def", "ghi", "jkl", "mno", "pgrs", "tuv", "wxyz"});
        len = digits.size();
        input = digits;

        getString(output, "", 0);
        return output;
    }

private:
    vector<string> table;
    string input;
    int len;
};