### 解题思路
考点：排序+数组
思路：先对二维数组表示的所有区间的左端点进行升序排序，然后从第二个区间（下标为1）开始遍历判断是否可以做合并操作：只要前一个区间的右端点大于等于当前区间的左端点，那说明这两个区间可以合并，合并后的区间左端点是前一个区间的左端点，只需要更新右端点为两个区间右端点的最大值即可。
否则，说明两个区间没有重叠，直接更新表示不重复区间的pos值。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size()) return {};

        //先把区间集合按照左端点从小到大进行排序
        sort(intervals.begin(), intervals.end(), less<vector<int>>());
        int pos = 0;//pos的值是每个不重叠的区间
        
        //从第二个区间开始去比较
        for (int i = 1; i < intervals.size(); ++i) 
        {
            //两个区间若能合并，则第一个区间的右端点一定大于等于第二个区间的左端点
            //比如[1,3] [2,6]
            if (intervals[pos][1] >= intervals[i][0]) 
            {
                //第一个区间的尾部需要更新为：两个区间的最大值即[1,6]
                intervals[pos][1] = max(intervals[pos][1], intervals[i][1]);
            } 
            else//没有重叠时 
            {
                //[1,6] [2,8]====>区间1就是目前的这个区间
                intervals[++pos] = intervals[i];
            }
        }

        intervals.resize(pos + 1);
        return intervals;
    }
   
};
```