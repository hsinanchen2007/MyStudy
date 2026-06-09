### 解题思路
双向遍历再乘积，正好符合题意

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, 1);
        vector<int> l(n, 1);
        vector<int> r(n, 1);
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] * a[i - 1];
        }
        for (int j = n - 2; j >= 0; j--) {
            r[j] = r[j + 1] * a[j + 1];
        }
        for (int k = 0; k < n; k++) {
            res[k] = l[k] * r[k];
        }
        return res;
    }
};
```