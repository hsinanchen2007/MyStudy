```c++
class Solution {
private:
    set<pair<int, int>> B;

public:
    string boldWords(vector<string>& words, string S) {
        for (string str : words) {
            int pos = -1;
            while ((pos = S.find(str, pos + 1)) != string::npos) {
                addxy(pos, pos + str.size() - 1);
            }
        }
        int count = 0;
        for (auto x : B) {
            S.insert(x.first + count * 7, "<b>");
            S.insert(x.second + 4 + count * 7, "</b>");
            count++;
        }
        return S;
    }
    void addxy(int x, int y) {
        auto iter = B.begin();
        while (iter != B.end()) {
            if (!(iter->first > y + 1 || iter->second < x - 1)) {
                x = min(x, iter->first);
                y = max(y, iter->second);
                iter=B.erase(iter);
            }
            else
                iter++;
        }
        B.insert(make_pair(x, y));
    }
};
```