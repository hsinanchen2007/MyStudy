```c++
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int a : arr2) {
            m[a] = 0;
        }
        for (int a : arr1) {
            if (m.count(a)) m[a]++;
            else q.push(a);
        }
        vector<int> r;
        for (int a : arr2) {
            int n = m[a];
            for (int i = 0; i < n; i++) r.push_back(a);
        }
        while (!q.empty()) {
            r.push_back(q.top());
            q.pop();
        }
        return r;
    }
};
```