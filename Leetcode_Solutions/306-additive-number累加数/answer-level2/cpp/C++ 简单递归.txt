```
class Solution {
public:
    string add(const string& s1, const string& s2) {
        string res;
        int n1 = s1.size();
        int n2 = s2.size();
        int carry = 0;
        int i = n1 - 1;
        int j = n2 - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int t1 = (i >= 0) ? s1[i--] - '0' : 0;
            int t2 = (j >= 0) ? s2[j--] - '0' : 0;
            res += ((t1 + t2 + carry) % 10) + '0';
            carry = (t1 + t2 + carry) / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool valid(string& num, int l1, int r1, int l2, int r2) {
        if ((r1 > l1 && num[l1] == '0') || (r2 > l2  && num[l2] == '0')) return false;
        if (r2 == num.size() - 1) return true;
        string s1 = num.substr(l1, r1 - l1 + 1);
        string s2 = num.substr(l2, r2 - l2 + 1);
        string s3 = add(s1, s2);
        int n = s3.size();
        if (r2 + n >= num.size() || s3.compare(0, n, num, r2 + 1, n) != 0) return false;
        return valid(num, l2, r2, r2 + 1, r2 + n);
    }
    bool isAdditiveNumber(string num) {
        int N = num.size();
        for (int i = 0; i < N / 2; ++i) {
            for (int j = i + 1; j < N - 1; ++j) {
                if (valid(num, 0, i, i + 1, j)) return true;
            }
        }
        return false;
    }
};
```
![image.png](https://pic.leetcode-cn.com/9dc241b59d9bf36ef5fab29c90dda1695c08c4ea7b43fdcab4cf407ca4db8140-image.png)
