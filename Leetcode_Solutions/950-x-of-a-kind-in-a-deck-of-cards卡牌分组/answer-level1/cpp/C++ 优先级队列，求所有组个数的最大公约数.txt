```
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() == 0) return false;

        unordered_map<int, int>m;
        for (auto val : deck) {
            m[val]++;
        }
        priority_queue<int> q;
        for (auto v : m) {
            q.push(v.second);
        }

        while (q.size() != 1) {
            int frist = q.top(); q.pop();
            int second = q.top(); q.pop();
            q.push(gcd(frist, second));
        }

        return q.top() >= 2;
    }
};
```
