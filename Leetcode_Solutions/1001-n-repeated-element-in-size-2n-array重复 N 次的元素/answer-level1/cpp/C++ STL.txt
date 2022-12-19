```c++
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (auto a : A) {
            if (s.count(a)) return a;
            s.insert(a);
        }
        return A[0];
    }
};
```