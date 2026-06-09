### 解题思路

1. 肯定希望拿最多的巧克力，但是拿到最大，又不够朋友分。
2. 有一个最大的临界点，刚好可以满足分配要求（当然比它小的选择也都满足）。

### 代码

```cpp
#define Dbg(x)  cout<<"[Debug] "<<__FUNCTION__<<"() L"<<__LINE__<<"\t"<<#x"="<<(x)<<endl

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int sum = std::accumulate(sweetness.begin(), sweetness.end(), 0);
        int l = 0;
        // int r = sum + 1;
        int r = sum / (K + 1) + 1;

        while(l + 1 < r) {
            int mid = (l + r) / 2;
            Dbg(mid);
            if(ok(sweetness, mid, K)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
    
    bool ok(vector<int>& sweetness, int v, int K) {
        int num = 0;
        int sum = 0;
        for(int sw: sweetness) {
            sum += sw;
            if(sum >= v) {
                sum = 0;
                num++;
            }
        }
        return num >= K+1;
    }
};
```