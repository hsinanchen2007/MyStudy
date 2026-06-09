### 解题思路
此处撰写解题思路
执行用时124ms，击败99.8%
将数组倒置，保存进位，模拟加法操作，最后再将数组倒置回来。
### 代码

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> vec;
        reverse(A.begin(), A.end());
        int flag = 0;
        for (int i = 0; i < A.size(); i++) {
            int temp = K % 10;
            int num = A[i] + temp + flag;
            K /= 10;
            if (num >= 10) {
                num %= 10;
                vec.push_back(num);
                flag = 1;
            } else {
                vec.push_back(num);
                flag = 0;
            }
        }
        if (K > 0) {
            while (K > 0) {
                int num = K % 10 + flag;
                K /= 10;
                if (num >= 10) {
                    num %= 10;
                    vec.push_back(num);
                    flag = 1;
                } else {
                    vec.push_back(num);
                    flag = 0;
                }
            }
        }
        if (flag == 1) {
            vec.push_back(1);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
```