![image.png](https://pic.leetcode-cn.com/4d7f13ad7b4886f489c36b1a30241d1f8434ca5f01e599c4f9e4922d36b275eb-image.png)

```
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int len = A.size();
        if (len < 3) return 0;
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        for (auto i = A.begin(); i != A.end() - 2; i++) {
            if (*i < *(i + 1) + *(i + 2)) return *i + *(i + 1) + *(i + 2);
        }
        return 0;
    }
};
```
