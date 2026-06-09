### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        vector<int> B;
        int temp = K;
        while(temp)
        {
            B.push_back(temp % 10);
            temp /= 10;
        }
        int index = 0;
        int carry = 0;
        if(A.size() > B.size())
        {
        for(int i = A.size() - 1 ; i >= 0 ; --i)
        {
            if(index < B.size())
                A[i] += B[index++];
            A[i] += carry;
            if(A[i] > 9)
            {
                carry = 1;
                A[i] %= 10;
            }
            else
                carry = 0;
        }
        if(carry == 1)
            ans.push_back(1);
        for(int i = 0 ; i < A.size() ; ++i)
            ans.push_back(A[i]);
        }
        else
        {
            index = A.size() - 1;
            for(int i = 0 ; i < B.size() ; ++i)
        {
            if(index >= 0)
                B[i] += A[index--];
            B[i] += carry;
            if(B[i] > 9)
            {
                carry = 1;
                B[i] %= 10;
            }
            else
                carry = 0;
        }
        if(carry == 1)
            ans.push_back(1);
        for(int i = B.size() - 1 ; i >= 0 ; --i)
            ans.push_back(B[i]);
        }
        return ans;
    }
};
```