### 解题思路
定义结构体VL保存value和label，根据value从大到小排序，再开辟一个label保存已用的次数，当次数小于限制的次数就将其加到结果ans中，不小于则继续往后扫描，当存放的个数等于限制的个数则退出循环返回结果ans。

### 代码

```cpp
class Solution {
    struct VL{
        int value;
        int label;
    };
    static bool cmp(VL a, VL b) {
        return a.value > b.value;
    }
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        VL vl[20000+5];
        short has[20000+5];
        memset(has, 0, sizeof(has));
        int n = values.size();
        for (int i=0; i<n; i++) {
            vl[i].value = values[i];
            vl[i].label = labels[i];
        }
        sort(vl, vl+n, cmp);
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (num_wanted == 0) break;
            if (has[vl[i].label]<use_limit) {
                ans += vl[i].value;
                has[vl[i].label]++;
                num_wanted--;
            }
        }
        return ans;
    }
};
```