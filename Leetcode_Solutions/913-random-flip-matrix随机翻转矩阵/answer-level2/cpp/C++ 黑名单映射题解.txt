### 解题思路
1，每次flip后都将flip的值记录到黑名单中，并将其映射到最后一个数上
2，每次flip后最后一个数都减一，因为之前的数已经被映射过了

### 代码

```cpp
class Solution {
public:
    int R;
    int C;
    int N;
    unordered_map<int, int> BL; // black list
    Solution(int n_rows, int n_cols) {
        R = n_rows;
        C = n_cols;
        N = R * C;
    }
    int find(int x) {
        if (BL.count(x)) {
            BL[x] = find(BL[x]);
            return BL[x];
        }
        return x;
    }
    vector<int> flip() {
        if (N == 0) return {};
        int k = find(rand() % N);
        BL[k] = --N;
        return {k / C, k % C};
    }
    
    void reset() {
        N = R * C;
        BL.clear();
    }
};
```

![image.png](https://pic.leetcode-cn.com/b3e2a4bb52d9db877ef8b2de26b5edaa668a6469fb02ac69d391fa07b55aecd1-image.png)
