### 解题思路
对于数组中的值
    1. 统计左边小于这个值的个数 和右边大于这个值的个数
    2. 统计左边大于这个值的个数 和右边小于这个值的个数
    3. 上面计算的个数相加

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int sz = rating.size();
        int res = 0;
        for(int i = 1; i<sz -1; ++i) {
            vector<int> more(2, 0);
            vector<int> less(2, 0);
            for(int j = 0; j < sz; ++j) {
                if(rating[j] < rating[i]) {
                    if(j < i) less[0]++;  // left less
                    else less[1]++; // right less
                }
                if(rating[j] > rating[i]) {
                    if(j < i) more[0]++; // left more;
                    else more[1]++; // right more;
                }
            }
            res += less[0] * more[1] + more[0] * less[1];
        }
        return res;
    }
};
```