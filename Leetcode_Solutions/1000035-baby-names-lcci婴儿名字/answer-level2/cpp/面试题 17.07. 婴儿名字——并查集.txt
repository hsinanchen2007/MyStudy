
```
class Solution {
private:
    void Splite(string& s, string& s1, string& s2) {
        string::size_type idx = s.find(',');
        if(idx == s.npos) {
            return;
        }
        s1 = s.substr(1, idx - 1);
        s2 = s.substr(idx + 1, s.size() - idx - 2);
    }
    void Insert(map<string, string>& m, string& s) {
        if(m.find(s) == m.end()) {
            m[s] = s;
        }
    }
    string Parent(map<string, string>& m, string &s) {
        string ss(s);
        Insert(m, s);
        while(s.compare(m[s]) != 0) {
            s = m[s];
        }
        m[ss] = s;
        return s;
    }
    bool Judge(string& s1, string& s2) {
        size_t count = min(s1.size(), s2.size());
        for(size_t i = 0; i < count; i++) {
            if(s1[i] < s2[i]) {
                return true;
            } else if(s1[i] > s2[i]) {
                return false;
            }
        }
        return s1.size() < s2.size();
    }
    void Union(map<string, string>& m, string& s1, string& s2) {
        string p1 = Parent(m, s1);
        string p2 = Parent(m, s2);
        if(Judge(s1, s2)) {
            m[p2] = p1;
        } else {
            m[p1] = p2;
        }
    }
    void Split(string& s, string& s1, int& count) {
        string::size_type l = s.find('(');
        if(l == s.npos) {
            count = 1;
            s1 = s;
            return;
        }
        s1 = s.substr(0, l);
        istringstream num(s.substr(l + 1, s.size() - l - 1));
        num >> count;
    }
    void Insert(map<string, string>& m, map<string, int>& res, string& s, int count) {
        string p = Parent(m, s);
        if(res.find(p) == res.end()) {
            res[p] = 0;
        }
        res[p] += count;
    }


public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        map<string, string> m;
        for(auto& i : synonyms) {
            string s1, s2;
            Splite(i, s1, s2);
            Insert(m, s1);
            Insert(m, s2);
            Union(m, s1, s2);
        }
        map<string, int> res;
        for(auto& i : names) {
            string s1;
            int count;
            Split(i, s1, count);
            Insert(m, res, s1, count);
        }

        vector<string> a;
        for(auto& i : res) {
            a.emplace_back(i.first + '(' + to_string(i.second) + ')');
        }
        return a;
    }
};
```
