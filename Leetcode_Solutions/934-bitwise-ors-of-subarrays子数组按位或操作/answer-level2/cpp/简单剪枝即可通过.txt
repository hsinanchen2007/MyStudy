### 解题思路
必须剪枝，否则超时，可以通过记录A[i]前最大可以置位的bit，全部置位后即可跳出循环

### 代码

```cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> mset;
        int prebit = 0;
        for (int i = 0; i < A.size(); i++) {
            int currbit = 0;
            for(int j = i; j >= 0; j--) {
                currbit |= A[j];
                mset.insert(currbit);
                if ((currbit & prebit) == prebit) {
                    break;  // 所有bit都置位则终止循环
                }
            }
            prebit |= A[i]; // 记录可以置位的bit
        }
        return mset.size();
    }
};
```