```
struct Node {
    int val;
    Node *children[26];
};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        rt = new Node();
    }
    
    void insert(string key, int val) {
        auto p = rt;
        for (auto c : key) {
            int i = c - 'a';
            if (!p->children[i])
                p->children[i] = new Node();
            p = p->children[i];
        }
        p->val = val;
    }
    
    int sum(string prefix) {
        auto p = rt;
        for (auto c : prefix) {
            if (!p) return 0;
            int i = c - 'a';
            p = p->children[i];
        }
        return sum_from(p);
    }
private:
    Node *rt;
    int sum_from(Node *rt) {
        if (!rt) return 0;
        int ans = rt->val;
        for (int i = 0; i < 26; ++i) {
            ans += sum_from(rt->children[i]);
        }
        return ans;
    }
};
```