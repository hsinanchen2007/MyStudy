```
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        int n = bulbs.size();
        set<int> bloom;
        bloom.insert(bulbs[0]);
        for (int i = 1; i < n; i++) {
            auto p = bloom.insert(bulbs[i]);
            auto it = p.first;
            if (it != bloom.begin()) {
                auto preit = it;
                preit--;
                if (bulbs[i] - *preit - 1 == K) {
                    return i + 1;
                }
            }
            if (++it != bloom.end()) {
                if (*it - bulbs[i] - 1 == K) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```
