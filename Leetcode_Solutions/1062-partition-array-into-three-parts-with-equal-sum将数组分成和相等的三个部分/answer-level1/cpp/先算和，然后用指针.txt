### 解题思路
主要先算和是多少，然后注意一下分三段即可
（本来想用前缀和，但是太菜了。。）
### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) {
            return false;
        }

        int pos1 = 0; 
        int pos2 = A.size() - 1;
        int lsum = A[pos1];
        int rsum = A[pos2];
        int avg = sum / 3;
        while (pos1 < pos2 -1) { //这个地方保证分3段 用例[-1, 1, -1, 1]
            if (lsum != avg) {
                pos1++;
                lsum += A[pos1];
            }

            if (rsum != avg) {
                pos2--;
                rsum += A[pos2];
            }
            //cout << pos1 << " " << pos2 << " " << lsum << " " << rsum << endl; 
            if (lsum == avg && rsum == avg && pos2 - pos1 > 1 ) {
                return true;
            }
        }

        return false;
    }
};
```