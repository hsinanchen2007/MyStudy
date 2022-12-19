双指针思路，一头一尾，遍历数组，偶数从头开始放，奇数从尾开始放，同时移动对应指针

代码：
```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int length = A.size();
        vector<int> ans(length);
        int i = 0, j = length - 1, k = 0;
        while(k < length) {
            if(A[k] % 2) {
                ans[j] = A[k];
                j--;
            }
            else {
                ans[i] = A[k];
                i++;
            }
            k++;
        }
        return ans;
    }
};
```
