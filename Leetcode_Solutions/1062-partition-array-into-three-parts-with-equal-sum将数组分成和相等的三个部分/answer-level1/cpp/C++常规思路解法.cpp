### 解题思路
思路很简单，首先计算所有数的和，如果不是3的倍数，则必不能分成三个和相等的部分。如果满足和为3的倍数，则总和除以3就是每部分的和，设置为target。从前往后加，每次达到target就得到了一部分，否则继续往后加。直到把所有数分成3等分。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int size = A.size();
        if(size<3) return false;
        int sum=0;
        for(int i=0;i<size;i++) {
            sum+=A[i];
        }
        if(sum%3!=0) return false;
        int target = sum/3;
        int ind = 0;
        vector<int> part(3,0);

        for(int i=0;i<size;i++) {
            part[ind]+=A[i];
            if(part[ind]!=target) {
                continue;
            }else {
                ind++;
                if(ind==3) return true;
            }
        }
        return false;
    }
};
```