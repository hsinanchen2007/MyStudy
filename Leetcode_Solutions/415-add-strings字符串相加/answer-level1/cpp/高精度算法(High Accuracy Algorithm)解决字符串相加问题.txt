```
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int>num_1;
        vector<int>num_2;
        string result;
        for (int i = 0; i < num1.size(); i++)
            num_1.push_back(num1[i] - '0');
        for (int i = 0; i < num2.size(); i++)
            num_2.push_back(num2[i] - '0');
        if (num_1.size() >= num_2.size()) {
            num_1.insert(num_1.begin(), 0);
            for (int i = num_1.size() - 1, j = num_2.size() - 1; i >= 0; i--, j--) {
                if (j >= 0) {
                    num_1[i] += num_2[j];
                    if (num_1[i] > 9) {
                        num_1[i] %= 10;
                        num_1[i - 1] += 1;
                    }
                }
                if (num_1[i] > 9) {
                    num_1[i] %= 10;
                    num_1[i - 1] += 1;
                }
                result += (num_1[i] + 48);
            }
        }
        else {
            num_2.insert(num_2.begin(), 0);
            for (int i = num_1.size() - 1, j = num_2.size() - 1; j >= 0; i--, j--) {
                if (i >= 0) {
                    num_2[j] += num_1[i];
                    if (num_2[j] > 9) {
                        num_2[j] %= 10;
                        num_2[j - 1] += 1;
                    }
                }
                if (num_2[j] > 9) {
                    num_2[j] %= 10;
                    num_2[j - 1] += 1;
                }
                result += (num_2[j] + 48);
            }
        }
        if (result[result.size() - 1] == '0')
            result.erase(result.begin() + result.size() - 1);
        reverse(result.begin(), result.end());
        return result;
    }
};
```