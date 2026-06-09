### 解题思路

思路：双指针，滑窗，带标签排序  好菜鸡 ~ 这么耗时
1、将所有的数字添加标签pair<int, int>添加到set中，set自动排序，先按数字再按标签，数字相同的情况放到了一起并去重
2、双指针滑窗，快指针往前移动，终点为新扩展列表长度，当满足条件时，慢指针往前移动，在满足条件的情况下刷新区间
3、hash存储每个标签的个数，快指针移动时增加，慢指针满足条件移动时减少

660ms 24M
--- wangtao HW-2020/3/18

### 代码

```cpp
class Solution {
public:
    bool valallin(vector<int>& hash)
    {
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == 0) return false;
        }
        return true;
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> hash(n, 0);
        set<pair<int, int>> setlist;
        vector<int> ans;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i].size() == 0) return ans;
            for (int j = 0; j < nums[i].size(); j++) {
                setlist.insert({nums[i][j], i});
            }
        }
        // 放vector好处理点吧
        vector<pair<int, int>> numlist;
        for (auto c : setlist) {
            numlist.push_back(c);
        }
        // 已排序去重的pair进行双指针遍历
        int i = 0;
        int j = 0;
        int left = 0;
        int right = INT_MAX;
        int minlen = INT_MAX;
        for (j = 0; j < numlist.size(); j++) {
            int k = numlist[j].second;
            hash[k]++;
            count++;
            if (count < n) continue;
            while (valallin(hash)) {
                int len = numlist[j].first - numlist[i].first;
                if (len < minlen) {
                    left = i;
                    right = j;
                    minlen = len;
                }
                hash[numlist[i].second]--;
                count--;
                i++;
            }
        }
        ans.push_back(numlist[left].first);
        ans.push_back(numlist[right].first);
        return ans;
    }
};
```