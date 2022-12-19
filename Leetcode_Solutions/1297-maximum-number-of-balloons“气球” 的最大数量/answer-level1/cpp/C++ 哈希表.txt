```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> times(256);
        for (const auto c : text)
            times[c]++;
        return min(min(min(min(times['b'], times['a']), times['l']/2), times['o'] / 2), times['n']);
    }
};
```