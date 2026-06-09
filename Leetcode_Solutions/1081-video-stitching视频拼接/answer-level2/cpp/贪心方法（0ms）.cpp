## 思路要点：
1. 先排序，按照区间[a, b]中的a从小到大排
2. 按照a从小到大遍历区间，使用变量r记录， 当前以a值为区间左值，能够达到的最远的右值，
3. 当r小于下个区间[a, b]中的a时，说明存在空隙，返回-1;

## 时间复杂度
排序O(nlogn) + 遍历O(n) = O(nlogn)
```cpp
bool cmp(vector<int> & a, vector<int> & b)
{
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T)
    {
        sort(clips.begin(), clips.end(), cmp);

        int ans = 0, r = 0;
        for (int i = 0; r < T && i < clips.size(); )
        {
            ans++;
            int l = r;
            for (; i < clips.size() && clips[i][0] <= l; ++i)
            {
                r = max(clips[i][1], r);
            }

            if (r == l && r < T-1)
                break;
        }
        if (r >= T-1)
            return ans;
        return -1;
    }
};

```