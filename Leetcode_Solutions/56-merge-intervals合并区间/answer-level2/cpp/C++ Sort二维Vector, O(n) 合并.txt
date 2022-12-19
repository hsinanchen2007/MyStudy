![Screenshot from 2020-02-11 22-19-04.png](https://pic.leetcode-cn.com/a665e92bc83faa39608d2c18bf071a94c92f3ff57ae6c16b3c3eb9cddaacd162-Screenshot%20from%202020-02-11%2022-19-04.png)


1. 按区间最小值Sort二维Vector。
2. 一次遍历完成合并： 选取当前区间，如果尾部大于下一区间的头，继续探寻，纪录最小和最大值。否则，存入重取区间。
* 相同方法，稍作改动就可以解57题。（57题是有序的，所以直接遍历一遍就行，只要注意插入新数组的与原数组的先后就行）


```
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    if (intervals.empty()) return ans;
    sort(intervals.begin(), intervals.end(),
        [&, this](vector<int> &v1, vector<int> &v2) { return v1.front() < v2.front();});
    
    int Size = intervals.size();
    for (int i = 0; i < Size; ++i) {
        auto tmp_vec = intervals[i];
        while (i + 1 < Size && tmp_vec.back() >= intervals[i+1].front()) {
            ++i;
            //tmp_vec.front() = min(tmp_vec.front(), intervals[i].front()); 由于头部已排序，这行不需要
            tmp_vec.back() = max(tmp_vec.back(), intervals[i].back());
        }
        ans.push_back(tmp_vec);
    }
    return ans;
}
```
