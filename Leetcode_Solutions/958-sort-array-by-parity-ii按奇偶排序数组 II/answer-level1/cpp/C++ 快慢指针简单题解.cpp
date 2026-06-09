```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int slow = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (slow <= i && slow % 2 == A[i] % 2) {
                swap(A[slow], A[i]);
                ++slow;
            }
        }
        return A;
    }
};
```
![image.png](https://pic.leetcode-cn.com/349cbc49316544db96e415158c2af0730e02a4f132a3eacd3dfa106f3d92d309-image.png)
