### 解题思路

![image.png](https://pic.leetcode-cn.com/e81a448d83de845727323904306e5e7e80d38324b88aa30eca63f7018609b8de-image.png)

(1)map保持有序，先将期间入map，如果左坐标一致，先合并入map
(2)再遍历一遍map，将连续有重叠的区间合并，合并后区间放入返回vector

### 代码

```cpp
class Solution {
public:
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ret;
    if (intervals.size() == 0) {
        return ret;
    }
    // first, insert zones to the map1 for ordering serials
    map<int, int> map1;
    map1[intervals[0][0]] = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        map<int, int>::iterator iter = map1.find(left);

        if (iter == map1.end()) {
            map1.insert(std::pair<int, int>(left, right));
        } else {
            map1[left] = max(map1[left], right);
        }
    }

    // merge map zones
    map<int, int>::iterator iter = map1.begin();
    vector<int> tmp;
    // 第一个区间左值，肯定是第一个元素左边值了。
    tmp.push_back(iter->first);
    int rigtmax = 0;

    for (; iter != map1.end(); iter++) {
        int currentLeft = iter->first;
        int currentRight = iter->second;
        // 这里注意：要记录重叠后的最大区间，所以要对右端取最大值。
        rigtmax = max(rigtmax, currentRight);
        
        iter++;
        if (iter != map1.end()) {
            int nextLeft = iter->first;
            int nextRight = iter->second;
            // 如果当前区间的右坐标大于下个区间的左坐标，那就可以和合并。
            // 如果小于，那就说明这个区间和下面有间断，找到一个区间输出区间到返回值了。
            if (rigtmax < nextLeft) {
                tmp.push_back(rigtmax);
                ret.push_back(tmp);
                tmp.clear();
                tmp.push_back(nextLeft);
                rigtmax = 0;
            } 

        } else {
            // 处理最后一个区间的右值
            tmp.push_back(rigtmax);
            ret.push_back(tmp);
            tmp.clear();
            rigtmax = 0;
        }
        iter--;
    }

    return ret;
}
};
```