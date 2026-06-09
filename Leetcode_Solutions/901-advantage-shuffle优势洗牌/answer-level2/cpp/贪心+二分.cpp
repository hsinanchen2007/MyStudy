### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        sort(A.begin(), A.end());
        for(int i = 0 ; i < B.size() ; ++i)
        {
            int left = 0, right = A.size() - 1;
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(A[mid] > B[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            if(A[left] > B[i])
            {
                ans.push_back(A[left]);
                A.erase(A.begin() + left);
            }
            else
            {
                ans.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return ans;
    }
};
```