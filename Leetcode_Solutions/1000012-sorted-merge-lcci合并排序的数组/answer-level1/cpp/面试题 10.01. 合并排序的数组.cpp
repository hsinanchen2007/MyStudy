### 题目描述
![image.png](https://pic.leetcode-cn.com/14895057d46d95d774d94ca60a4f56e8f4ab08eb7b980ec1c36008230505cc02-image.png)


### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i = 0; i < n; i++) {
            A[m + i] = B[i];
        }

        sort(A.begin(), A.end());

    }
};
```
![image.png](https://pic.leetcode-cn.com/29b6de45f31c5cbdcda959bf167e1d1a43a4af55655094769c22c8e4b1931fbf-image.png)
