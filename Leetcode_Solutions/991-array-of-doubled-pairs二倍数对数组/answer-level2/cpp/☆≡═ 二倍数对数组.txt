1. 题目要求的数组 A 可以分为长度相等的数组 B 和 C 并且 B[i] * 2 = C[i]。
2. 可以通过同时删除数组中的 A[i] 和 2 * A[i] 判断 数组 A 是否满足要求。
3. 但是对于正数 x < x * 2，对于负数 2 * y < y，增加了判断的麻烦。
4. 当 u * 2 = v 时，u 和 v 同正或同负，可以不失一般性地对 A 中所有数字取绝对值。
5. 然后从最大的数字开始删除，当一个数字不满足要求时，返回 false。
6. 0 * 2 = 0，可以忽略0。
```
class Solution {
public:
    bool canReorderDoubled(const vector<int>& A) {
        map<int, int> dict;
        for (const auto& n : A)
            ++dict[abs(n)];
        dict.erase(0);
        while (!dict.empty()) {
            const int maximum = dict.rbegin()->first;
            const int half = maximum / 2;
            if (maximum & 0x1) return false;
            else if (dict[half] < dict[maximum]) return false;
            dict[half] -= dict[maximum];
            dict.erase(maximum);
            if (dict[half] == 0) dict.erase(half);
        }
        return true;
    }
};
```
