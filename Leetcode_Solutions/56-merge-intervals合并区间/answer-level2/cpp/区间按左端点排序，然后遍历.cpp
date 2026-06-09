这题的常规思路比较简单，首先肯定能想到的是，将区间按照左端点从小到大进行排序，然后遍历，将能合并的区间合并。

看到好多评论区和解题区的，给vector<int>重载了一个比较运算，其实可以不用，对于vector<T>，只要T能比较，vector<T>也能比较，因此这一步可以省掉直接对intervals调用sort即可，很方便。（当然如果你要降序，只能自己写了）

其次是在遍历过程中，利用了双指针，每次选择左侧指针指向的区间作为一个基本区间，右边指针往后走，每当遇到可以合并的区间，就扩展到左侧指针的基本区间中
总体看，遍历一遍即可。

算法的时间复杂度为O(Nlog(N))，空间复杂度为O(1)。

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals);
};

vector<vector<int>> Solution::merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ret;
    if (intervals.empty())
        return ret;
    // vector<int>可以直接比较，省去写Compare对象了
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size();) {
        int j = i + 1;
        // 将intervals[i]作为基本区间，每次进行扩展
        while (j < intervals.size() && intervals[j][0] <= intervals[i][1]) {
            intervals[i][1] = max(intervals[i][1], intervals[j][1]);
            j++;
        }
        ret.push_back(intervals[i]);
        i = j;
    }
    return ret;
}
```

