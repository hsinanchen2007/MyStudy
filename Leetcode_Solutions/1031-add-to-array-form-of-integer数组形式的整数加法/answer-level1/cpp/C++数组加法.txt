vector用的不是很熟，用的最笨的方法写的，浪费了不少内存
![1.png](https://pic.leetcode-cn.com/e7ca5872da719c619a2068bc830787b010ba9c161e29a247e0a94a5b55658bd1-1.png)

```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        vector<int> idx; // 表示剩余的进位
        int result[A.size()];
        int tmp; //表示进位
        tmp = (A[A.size() - 1] + K) / 10;
        result[A.size() - 1] =  (A[A.size() - 1] + K) % 10;
        for (int i = A.size() - 2; i >= 0; i--) {
            result[i] = (A[i] + tmp) % 10;
            tmp = (A[i] + tmp) / 10;
        }
        while (tmp != 0) {
            idx.push_back(tmp % 10);
            tmp /= 10;
        }
        if (!idx.empty()) {
            for (int i = idx.size() - 1; i >=0; i--) {
                res.push_back(idx[i]);
            } 
        }
        for (int i = 0; i < A.size(); i++) {
            res.push_back(result[i]);
        }
        return res; 
    }
};
```

