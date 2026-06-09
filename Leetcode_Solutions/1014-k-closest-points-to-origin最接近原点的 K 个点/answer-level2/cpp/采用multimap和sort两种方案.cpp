### 解题思路
第一版：
采用multimap(默认升序)【可能存在到原点距离相同的坐标点，因此采用multimap】，以坐标点到原点的距离为key，以坐标点vector<int>为value。
然后，获取前K个元素作为返回结果。
执行用时 :432 ms, 在所有 cpp 提交中击败了26.98%的用户
内存消耗 :57.3 MB, 在所有 cpp 提交中击败了27.21%的用户

第二版：
直接对vector<vector<int>>& points使用std::sort进行排序，然后取前K个元素。
执行用时 :1056 ms, 在所有 cpp 提交中击败了10.32%的用户
内存消耗 :189.2 MB, 在所有 cpp 提交中击败了8.47%的用户
性能和内存反而不如使用multimap

### 代码

```cpp
【第一版】
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, vector<int> > closests;
        for (auto it = points.begin(); it != points.end(); ++it) {
            int x = (*it)[0];
            int y = (*it)[1];
            closests.insert(make_pair(x * x + y * y, *it));
        }

        auto iter = closests.begin();
        vector<vector<int>> result;
        for (int i = 0; i < K; ++i) {
            result.insert(result.end(), iter->second);
            ++iter;
        }

        return result;
    }
};

【第二版】
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2) {
            return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]); 
        });

        vector<vector<int>> result(points.begin(), points.begin() + K);
        return result;
    }
};
```