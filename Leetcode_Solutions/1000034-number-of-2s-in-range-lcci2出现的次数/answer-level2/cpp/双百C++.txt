### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOf2sInRange(int n) {
        // 统计每一位上2的个数
        // 0 <= xxx2yyy <= abcdefg
        // xxx = 0-abc-1, yyy = 0-999, 即abc * power(i)
        // xxx = abc;
        //  1. d < 2, 0
        //  2. d = 2, 0 - efg
        //  3. d > 2, 0 - 999
        vector<int> num;
        while (n) num.push_back(n % 10), n /= 10;

        reverse(num.begin(), num.end());
        int res = 0, len = num.size(), left, right;
        for (int i = 0; i < len; i ++) {
            res += get(num, 0, i - 1) * power10(len - 1 - i);
            if (num[i] > 2) res += power10(len - 1 - i);
            else if (num[i] == 2) res += get(num, i + 1, len - 1) + 1;
        }
        return res;
    }

    int get(vector<int>& num, int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i ++) res = res * 10 + num[i];
        return res;
    }

    int power10(int n) {
        int res = 1;
        while (n --) res *= 10;
        return res;
    }
};
```