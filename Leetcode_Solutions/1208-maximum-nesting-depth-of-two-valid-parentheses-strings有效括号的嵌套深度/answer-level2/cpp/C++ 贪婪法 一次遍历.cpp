```C++ []
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int N = seq.size();
        vector<int> res(N, 0);
        int A = 0;
        int B = 0;
        for (int i = 0; i < N; ++i) {
            char c = seq[i];
            if (c == '(') {
                if (A > B) {
                    ++B;
                    res[i] = 1;
                } else {
                    ++A;
                }
            } else {
                if (A < B) {
                    --B;
                    res[i] = 1;
                } else {
                    --A;
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d2ac68ff8c791b0a3f800f62959cd19fe23cb9be6e0da0d5c35a63a16862c677-image.png)


