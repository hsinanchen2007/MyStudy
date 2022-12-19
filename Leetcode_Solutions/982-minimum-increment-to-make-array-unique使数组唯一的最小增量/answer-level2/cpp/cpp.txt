### 解题思路
排序后，使用hashset，然后每次在上一次安插的地方继续安插。

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        unordered_set<int> st;
        //for (int val : A) st.insert(val);
        sort(A.begin(), A.end());
        int ret = 0, last = -1;
        for (int val : A) {
            if (val > last) last = val;
            while (st.count(last)) last ++;
            st.insert(last);
            ret += last - val;
        }
        return ret;
    }
};
```