
首先声明，该方法速度和效率都不是特别高，但是简单易懂。

本题就是对距离进行排序，但是有两个问题，一个问题是两个坐标具有相同的距离时，排序会不会只保留一个；另一个问题是只对距离排序之后不知道距离原来的索引了，找不到坐标了。
这里使用二维vector解决这一问题，不仅可以保留索引，也解决了不同坐标具有相同距离的情况。

![2019-10-15 14:30:29屏幕截图.png](https://pic.leetcode-cn.com/1e1dcec455c64122a221dad6fa3a7635c5fb681cc7049b9a69b6cbdbc3b04720-2019-10-15%2014:30:29%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> vvlocation;
        vector<vector<float>> vvdistance;
        float distance;
        for( int i=0; i<points.size(); i++ )
        {
            distance=sqrt( pow(points[i][0],2) + pow(points[i][1],2) );
            vvdistance.push_back({distance,i});
        }
        sort(vvdistance.begin(), vvdistance.end());
        for( int i=0; i<K; i++ )
        {
            vvlocation.push_back( points[vvdistance[i][1]] );
        }
        return vvlocation;
    }
};
```