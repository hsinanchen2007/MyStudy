```cpp
class UnionFind {
public:
    vector<int> nodes;

    UnionFind(int n) {
        nodes = vector<int>(n);
        for (int i = 0; i < n; ++i)
            nodes[i] = i;
    }

    int find(int& i) {
        if (nodes[i] == i)
            return i;
        return nodes[i] = find(nodes[i]);
    }

    void unionAB(int& a, int& b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            nodes[pa] = b;
    }
};

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> words;
        int ptr = 0;
        int cur = 0;
        while (cur < text.size()) {
            while (cur < text.size() && text[cur] != ' ')
                ++cur;
            words.push_back(text.substr(ptr, cur - ptr));
            ptr = cur + 1;
            ++cur;
        }
        set<string> wordsSet;
        unordered_map<int, string> i2s;
        unordered_map<string, int> s2i;
        for (vector<string>& vec : synonyms)
            for (string& str : vec)
                wordsSet.insert(str);
        int count = 0;
        for (string str : wordsSet) {
            i2s[count] = str;
            s2i[str] = count;
            ++count;
        }
        UnionFind uf(i2s.size());
        for (vector<string>& vec : synonyms)
            if (uf.find(s2i[vec[0]]) != uf.find(s2i[vec[1]]))
                uf.unionAB(s2i[vec[0]], s2i[vec[1]]);
        unordered_map<int, vector<int>> dic;
        for (int i = 0; i < uf.nodes.size(); ++i)
            dic[uf.find(i)].push_back(i);
        vector<string> result;
        vector<string> tmp;
        dfsAddWords(s2i, i2s, dic, uf, result, tmp, words, 0);
        return result;
    }

    string outputStr(vector<string>& in) {
        string result = "";
        for (string& str : in)
            result += str + ' ';
        result.pop_back();
        return result;
    }

    void dfsAddWords(unordered_map<string, int>& s2i, unordered_map<int, string>& i2s, unordered_map<int, vector<int>>& dic, UnionFind& uf, vector<string>& result, vector<string>& cur, vector<string>& pattern, int index) {
        if (index == pattern.size()) {
            result.push_back(outputStr(cur));
            return;
        }
        if (!s2i.count(pattern[index])) {
            cur.push_back(pattern[index]);
            dfsAddWords(s2i, i2s, dic, uf, result, cur, pattern, index + 1);
            cur.pop_back();
        }
        else {
            for (int& i : dic[uf.find(s2i[pattern[index]])]) {
                cur.push_back(i2s[i]);
                dfsAddWords(s2i, i2s, dic, uf, result, cur, pattern, index + 1);
                cur.pop_back();
            }
        }
    }
};
```
