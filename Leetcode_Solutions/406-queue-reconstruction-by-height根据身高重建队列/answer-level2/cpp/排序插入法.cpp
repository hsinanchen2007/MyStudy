### 解题思路
先排序，再逐个插入

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty() || people.size() == 1) {
            return people;
        }
        sort(people.begin(), people.end(), [](const vector<int> p1, const vector<int> p2) {
            if (p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            return p1[0] > p2[0];
        });
        for(vector<int> vec : people) {
            for (int i : vec) {
                cout << i ;
            }
            cout <<" ";
        }
        cout <<endl;
        vector<vector<int>> vecResult;
        int maxCount = people[0][0];
        for (vector<int> p : people) {
            int count = 0;
            int curK = p[1];
            if (p[0] == maxCount) {
                vecResult.push_back(p);
                continue;
            }
            vecResult.insert(vecResult.begin()+curK, p);
        }

        return vecResult;
    }
};
```