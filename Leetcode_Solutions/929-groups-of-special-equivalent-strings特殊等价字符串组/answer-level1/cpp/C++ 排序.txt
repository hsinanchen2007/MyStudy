```c++
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (auto& a : A) {
            string odd, even;
            for (int i = 0; i < a.size(); i++) {
                i % 2 == 0 ? even += a[i] : odd += a[i];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            s.insert(odd + even);
        }
        return s.size();
    }
};
```