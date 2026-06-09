平均8ms，最快一次4ms。
```
string minAbbreviation(string target, vector<string>& dictionary) {
    int n = (int) target.size();
    int bound = 1<<n;
    unordered_set<int> dict;
    for (auto &s : dictionary) {
        if (s.size() != n) continue;
        int bits = 0;
        int cur = bound>>1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != target[i]) {
                bits |= cur;
            }
            cur >>= 1;
        }
        dict.emplace(bits);
    }
    if (dict.empty()) return to_string(target.size());
    
    int minSize = n, minMask = bound-1;
    auto len = [&](int mask) {
        int count = 0, res = 0;
        int temp = n;
        while (temp--) {
            if (mask&1) {
                if (count) ++res;
                ++res;
                count = 0;
            } else {
                ++count;
            }
            mask >>= 1;
        }
        if (count) ++res;
        return res;
    };
    for (int mask = 1; mask < bound; mask++) {
        int size = len(mask);
        if (size >= minSize) continue;
        bool collision = false;
        for (auto i : dict) {
            if (!(i&mask)) {
                collision = true;
                break;
            }
        }
        if (collision) continue;
        minSize = size;
        minMask = mask;
    }
    
    ostringstream oss;
    int cur = bound>>1, count = 0;
    for (int i = 0; i < n; i++) {
        if (minMask&cur) {
            if (count) oss << count;
            oss << target[i];
            count = 0;
        } else ++count;
        cur >>= 1;
    }
    if (count) oss << count;
    return oss.str();
}
```
