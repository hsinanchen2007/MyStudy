```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> B(A.size(), 0);
        int odd = 1;//奇数坐标
        int even = 0;//偶数坐标
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] % 2 == 0) {
                B[even] = A[i];
                even = even + 2;
            } else {
                B[odd] = A[i];
                odd = odd + 2;
            }
        }
        return B;
    }
};
```
![image.png](https://pic.leetcode-cn.com/2e46ff3d38765a5e970edf8f8e16c2f1d97bea90e1a9900ac9e89d3757c98858-image.png)
