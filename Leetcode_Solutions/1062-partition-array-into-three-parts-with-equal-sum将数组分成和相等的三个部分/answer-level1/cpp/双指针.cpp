### 解题思路
双指针

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum%3!=0) return false;
        int left = 0, right = A.size()-1;
        int left_sum = A[left], right_sum = A[right];
        while(left+1<right)
        {
            if(left_sum==sum/3 && right_sum==sum/3) return true;
            if(left_sum!=sum/3)
            {
                left++;
                left_sum += A[left];
            }
            if(right_sum!=sum/3)
            {
                right--;
                right_sum += A[right];
            }
        }
        return false;
    }
};
```