从大到小排序，然后把所有大于0的前缀和加起来。
一旦出现小于0的前缀和，那么此后的前缀和肯定都小于0。
最小的非负前缀的逆序就是做菜顺序。

```
class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        int sum = 0;
        int ans = 0;
        for (int n : s) {
            sum += n;
            if (sum < 0) break;
            ans += sum;
        }
        return ans;
    }
};
```
