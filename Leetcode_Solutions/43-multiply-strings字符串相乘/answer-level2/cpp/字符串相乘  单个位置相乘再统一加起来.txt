```
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1 + len2;
        int result[len];

        for (int l = 0; l < len; l++) {
            result[l] = 0;
        }

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                result[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int k = 0; k < len1 + len2; k++) {
            if (result[k] > 9) {
                int temp = result[k];
                result[k] = temp % 10;
                result[k + 1] += temp / 10;
            }
        }

        int pos = result[len1 + len2 - 1] == 0 ? len1 + len2 - 2 : len1 + len2 - 1;
        string ans = "";
        for (; pos >= 0; --pos) {
            ans += result[pos] + '0';
        }

        return ans;
    }
};
```
