### 解题思路
sum前缀和即可

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        long long s[100005];
        s[0] = 0;
        for (int i = 1; i <= target; i++) {
            s[i] = s[i - 1] + i;
        }
        vector<vector<int>>ve;
        int i = 1, j = 2, e = target / 2 + 1;
        while (j <= e) {
            if (s[j] - s[i - 1] == target) {
                vector<int>v;
                for (int t = i; t <= j; t++) v.push_back(t);
                ve.push_back(v);
                i++;//因为不可能j再增加得到target
            }
            else if (s[j] - s[i - 1] > target) i++;
            else j++;
            /*cout << i << j << endl;
            system("pause");*/
        }
        return ve;
    }
};
```