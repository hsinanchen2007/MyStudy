![image.png](https://pic.leetcode-cn.com/b1c6d7b118c3ac4bd8ad758d1b3b986fd304e80c19afda2a380c58a914fda1ad-image.png)

用入度来处理，比较典型的拓扑排序题目，思路跟官方题解的解法二是一致的。
注意结果不正确说明有环，题目要求直接返回空。

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> records(numCourses, 0);
        vector<list<int>> relations(numCourses, list<int>());
        for (const auto& prerequisite : prerequisites) {
            records[prerequisite[0]]++;
            relations[prerequisite[1]].emplace_back(prerequisite[0]);
        }

        vector<int> results;
        results.reserve(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (records[i] == 0) {
                trans_.emplace(i);
            }
        }

        while (!trans_.empty()) {
            auto temp = trans_.front();
            results.emplace_back(temp);
            trans_.pop();
            for (auto num : relations[temp]) {
                if (--records[num] == 0) {
                    trans_.emplace(num);
                }
            }
        }

        if (results.size() != numCourses) {
            results.clear();
        }

        return results;
    }
private:
    queue<int> trans_;
};
```


