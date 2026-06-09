### 解题思路
见注释

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) { // 计数法
        int ans = 0, A_size = A.size();
        int cnt[40005] = {0};
        int _max = -1, _min = INT_MAX;

        for(int i = 0; i < A_size; ++i){ // 记录A中各数据出现次数
            int num = A[i];
            ++cnt[num];
            _max = max(_max, num);
            _min = min(_min, num);
        }
        for(int i = _min; i <= _max; ++i){ // 若A[i]出现超过1次，则需要将A[i]进行cnt[i]-1次move移动到A[i+1];
            if(cnt[i] > 1){
                cnt[i + 1] += cnt[i] - 1;
                ans += cnt[i] - 1;
            }
        }
        if(cnt[_max + 1] > 1){ // 若cnt[_max + 1]中次数大于1，将其中的d = cnt[_max + 1] - 1依次后移，需要d+(d-1)+...+1次，等差求和即可。
            int d = cnt[_max + 1] - 1;
            ans += (1 + d) * d / 2;
        }

        return ans;
    }
};
```